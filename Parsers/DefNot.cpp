// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_not() {
    // DefNot := NotOp Operand Target
    TRY(ensure_opcode(Opcode::DefNot));
    
    auto operand_0 = TRY(parse_operand());
    auto target_1 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefNot) + operand_0->get_size() + target_1->get_size();
    auto payload_size = 0;

    auto self = new Not(full_size, payload_size);

    return self;
}
