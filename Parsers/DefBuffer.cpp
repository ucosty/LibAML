// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_buffer() {
    // DefBuffer := BufferOp PkgLength BufferSize ByteList
    TRY(ensure_opcode(Opcode::DefBuffer));
    
    size_t package_length_size = 0;
    auto package_length = TRY(parse_pkg_length(&package_length_size));
    auto buffer_size_1 = TRY(parse_buffer_size());
    auto byte_list_2 = TRY(parse_byte_list());

    auto full_size = opcode_length(Opcode::DefBuffer) + package_length_size + buffer_size_1->get_size() + byte_list_2->get_size();
    auto payload_size = 0;

    auto self = new Buffer(full_size, payload_size);

    return self;
}
