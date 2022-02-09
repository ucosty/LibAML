// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_l_greater_equal() {
    // DefLGreaterEqual := LgreaterEqualOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLGreaterEqual));
    
    auto operand_0 = TRY(parse_operand());
    auto operand_1 = TRY(parse_operand());

    auto full_size = opcode_length(Opcode::DefLGreaterEqual) + operand_0->get_size() + operand_1->get_size();
    auto payload_size = 0;

    auto self = new LGreaterEqual(full_size, payload_size);

    return self;
}
