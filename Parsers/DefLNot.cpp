// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_l_not() {
    // DefLNot := LnotOp Operand
    TRY(ensure_opcode(Opcode::DefLNot));
    
    auto operand_0 = TRY(parse_operand());

    auto full_size = opcode_length(Opcode::DefLNot) + operand_0->get_size();
    auto payload_size = 0;

    auto self = new LNot(full_size, payload_size);

    return self;
}
