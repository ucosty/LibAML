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
    filename = "{}/Elements/{}.cpp".format(output_path, name)
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
    filename = "{}/Elements/{}.h".format(output_path, name)
    with open(filename, 'w') as file:
        file.write(template.format(name))


def generate_comment(opcode_name, terms_raw):
    term_names = [opcode_name for (term_type, opcode_name) in terms_raw]
    return "// {} := {}".format(opcode_name, ' '.join(term_names))


def generate_sub_parser_size_calc(index, term, list):
    _, term_name = term
    instance_name = get_instance_name(term_name)
    if term_name == 'PkgLength':
        list += " + package_length_size"
    else:
        list += " + {}_{}->get_size()".format(instance_name, index)
    return list


def generate_sub_parser_call(index, term, sub_parser_list):
    _, term_name = term
    parser = get_parser_name(term_name)
    instance_name = get_instance_name(term_name)
    if term_name == 'PkgLength':
        sub_parser_list.append("    size_t package_length_size = 0;")
        sub_parser_list.append("    auto package_length = TRY(parse_pkg_length(&package_length_size));")
    else:
        sub_parser_list.append("    auto {}_{} = TRY({}());".format(instance_name, index, parser))


def generate_parser_source(filename, method_name, opcode_name, class_name, terms):
    template = """// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_{method_name}() {{
    {comment}
    TRY(ensure_opcode(Opcode::{opcode_name}));
    
{sub_parsers}
{object_size}
    auto self = new {class_name}(full_size, payload_size);
{metadata}
    return self;
}}
"""
    # print("Result<Element *> parse_{method_name}();".format(method_name=method_name))

    element_sizes = ""
    sub_parser_list = []

    for index, term in enumerate(terms[1:]):
        generate_sub_parser_call(index, term, sub_parser_list)
        element_sizes = generate_sub_parser_size_calc(index, term, element_sizes)
    sub_parsers = '\n'.join(sub_parser_list)

    metadata = ""

    object_size_template = """
    auto full_size = opcode_length(Opcode::{opcode_name}){element_sizes};
    auto payload_size = 0;
"""
    object_size = object_size_template.format(opcode_name=opcode_name
                                              , element_sizes=element_sizes)

    comment = generate_comment(opcode_name, terms)
    with open(filename, 'w') as file:
        file.write(template.format(method_name=method_name
                                   , opcode_name=opcode_name
                                   , class_name=class_name
                                   , comment=comment
                                   , sub_parsers=sub_parsers
                                   , metadata=metadata
                                   , object_size=object_size))


def generate_cmake_lists(output_path, files):
    file_list = ' '.join(files)
    template = "set(PARSERS_GENERATED {} PARENT_SCOPE)".format(file_list)
    filename = "{}/Parsers/CMakeLists.txt".format(output_path)
    with open(filename, 'w') as file:
        file.write(template)


def get_method_name(term_name: str):
    return to_snake_case(term_name.removeprefix("Def"))


def get_parser_name(term_name: str):
    return "parse_" + to_snake_case(term_name.removeprefix("Def"))


def get_instance_name(term_name: str):
    return to_snake_case(term_name.removeprefix("Def"))


def generate_method(output_path, name, terms):
    _, opcode_name = terms[0]

    filename = "{}/Parsers/{}.cpp".format(output_path, name)
    method_name = get_method_name(name)
    opcode_name = opcodes.get_opcode(opcode_name)
    class_name = opcodes.get_class_name(name)

    generate_parser_source(filename, method_name, opcode_name, class_name, terms)
    generate_class_source(output_path, opcodes.get_class_name(name))
    generate_class_header(output_path, opcodes.get_class_name(name))


def generate(methods, output_path):
    for (name, terms) in methods:
        generate_method(output_path, name, terms)

    parser_files = ["${{CMAKE_CURRENT_SOURCE_DIR}}/{}.cpp".format(name) for (name, _) in methods]
    generate_cmake_lists(output_path, parser_files)

    for (name, terms) in methods:
        print("#include \"{}.h\"".format(opcodes.get_class_name(name)))


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
