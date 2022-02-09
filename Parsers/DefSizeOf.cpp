// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_size_of() {
    // DefSizeOf := SizeOfOp SuperName
    TRY(ensure_opcode(Opcode::DefSizeOf));
    
    auto super_name_0 = TRY(parse_super_name());

    auto full_size = opcode_length(Opcode::DefSizeOf) + super_name_0->get_size();
    auto payload_size = 0;

    auto self = new SizeOf(full_size, payload_size);

    return self;
}
