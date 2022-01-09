#!/usr/bin/env python
import json
import sys
from enum import Enum

import opcodes


class TermType(Enum):
    Ensure = 1
    Term = 2
    Metadata = 3
    TermList = 4


def to_snake_case(str):
    res = [str[0].lower()]
    for c in str[1:]:
        if c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            res.append('_')
            res.append(c.lower())
        else:
            res.append(c)
    return ''.join(res)


def parse_expression(expression):
    parts = expression.split(":=")
    name = parts[0].strip()
    terms = parts[1].strip().split(' ')
    return name, terms


def parse_term(term: str):
    parts = term.split(':')
    if len(parts) == 1:
        if term == "TermList":
            return TermType.TermList, term
        return TermType.Term, term
    if len(parts) == 2:
        if parts[1] == 'ensure':
            return TermType.Ensure, parts[0]
        if parts[1] == 'metadata':
            return TermType.Metadata, parts[0]


# Result<Element *> Parser::parse_name() {
#     // DefName := NameOp NameString DataRefObject
#     TRY(ensure_opcode(Opcode::DefName));
#     auto name_string = TRY(parse_name_string());
#     auto data_ref = TRY(parse_data_ref());
#     auto self = new Name(opcode_length(Opcode::DefName) + data_ref->get_size() + name_string->get_size());
#     self->add_metadata(Metadata::StringConst, name_string);
#     self->add_metadata(Metadata::ObjectRef, data_ref);
#     return self;
# }
def generate_class_source(output_path, name):
    template = """// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "{0}.h"

void {0}::print(int depth) {{
    indent(depth * 2);
    fmt::print("- {0}\\n");
}}

std::string {0}::value_string() {{
    return "[{0}]";
}}
"""
    filename = "{}/Elemenets/{}.cpp".format(output_path, name)
    with open(filename, 'w') as file:
        file.write(template.format(name))


def generate_class_header(output_path, name):
    template = """// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Element.h"

class {0} : public Element {{
ELEMENT_OBJ(ElementType::TermArg)
public:
    {0}(size_t size, size_t payload_size) : m_size(size), m_payload_size(payload_size) {{}}

    [[nodiscard]] std::string value_string() override;
}};
"""
    filename = "{}/Elemenets/{}.h".format(output_path, name)
    with open(filename, 'w') as file:
        file.write(template.format(name))


def generate_comment(opcode_name, terms_raw):
    term_names = [opcode_name for (term_type, opcode_name) in terms_raw]
    return "// {} := {}".format(opcode_name, ' '.join(term_names))


def generate_parser_source(filename, method_name, opcode_name, class_name, terms):
    template = """// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_{method_name}() {{
    {comment}
    TRY(ensure_opcode(Opcode::{opcode_name}));
    auto self = new {class_name}(full_size, payload_size);
    return self;
}}
"""
    comment = generate_comment(opcode_name, terms)
    with open(filename, 'w') as file:
        file.write(template.format(method_name=method_name, opcode_name=opcode_name, class_name=class_name, comment=comment))


def generate_class(output_path, name):
    generate_class_source(output_path, name)
    generate_class_header(output_path, name)


def get_method_name(term_name: str):
    return to_snake_case(term_name.removeprefix("Def"))


def generate_method(output_path, name, terms):
    _, opcode_name = terms[0]

    filename = "{}/Parsers/{}.cpp".format(output_path, name)
    method_name = get_method_name(name)
    opcode_name = opcodes.get_opcode(opcode_name)
    class_name = opcodes.get_class_name(name)

    generate_parser_source(filename, method_name, opcode_name, class_name, terms)
    generate_class(output_path, opcodes.get_class_name(name))


def generate(methods, output_path):
    for (name, terms) in methods:
        generate_method(output_path, name, terms)


def main():
    filename = sys.argv[1]

    if len(sys.argv) == 3:
        output_path = sys.argv[2]
    else:
        output_path = './output'

    with open(filename, 'r') as expression_file:
        data = expression_file.read()

    expressions = json.loads(data)

    # Format of the expressions is as follows:
    # Term := Term [Term]
    methods = []
    for expression in expressions:
        name, terms = parse_expression(expression)
        terms_parsed = [parse_term(term) for term in terms]
        methods.append((name, terms_parsed))
    generate(methods, output_path)


if __name__ == "__main__":
    main()
