// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_add() {
    // DefAdd := AddOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefAdd));
    
    auto operand_0 = TRY(parse_operand());
    auto operand_1 = TRY(parse_operand());
    auto target_2 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefAdd) + operand_0->get_size() + operand_1->get_size() + target_2->get_size();
    auto payload_size = 0;

    auto self = new Add(full_size, payload_size);

    return self;
}
