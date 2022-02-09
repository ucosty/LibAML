// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefMethod := MethodOp PkgLength NameString MethodFlags TermList
Result<Element *> Parser::parse_method() {
    TRY(ensure_opcode(Opcode::DefMethod));
    size_t package_length_size = 0;
    auto package_length = TRY(parse_pkg_length(&package_length_size));
    auto name = TRY(parse_name_string());
    auto flags = TRY(m_byte_reader.read_byte());
    auto full_size = package_length + opcode_length(Opcode::DefMethod);
    auto payload_size = package_length - package_length_size - name->get_size() - sizeof(flags);

    fmt::print("Method: package_length = {}, name = {}, full_size = {}, payload_size = {}\n", package_length,
               name->value_string(), full_size, payload_size);

    auto self = new Method(full_size, payload_size);
    self->add_metadata(Metadata::Name, name);
    if (payload_size > 0) {
        TRY(parse_term_list(self));
    }
    return self;
}
