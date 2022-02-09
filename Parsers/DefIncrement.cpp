// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_increment() {
    // DefIncrement := IncrementOp SuperName
    TRY(ensure_opcode(Opcode::DefIncrement));
    
    auto super_name_0 = TRY(parse_super_name());

    auto full_size = opcode_length(Opcode::DefIncrement) + super_name_0->get_size();
    auto payload_size = 0;

    auto self = new Increment(full_size, payload_size);

    return self;
}
