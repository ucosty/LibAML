// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_l_or() {
    // DefLOr := LorOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLOr));
    
    auto operand_0 = TRY(parse_operand());
    auto operand_1 = TRY(parse_operand());

    auto full_size = opcode_length(Opcode::DefLOr) + operand_0->get_size() + operand_1->get_size();
    auto payload_size = 0;

    auto self = new LOr(full_size, payload_size);

    return self;
}
