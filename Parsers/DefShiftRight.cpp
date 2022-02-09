// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_shift_right() {
    // DefShiftRight := ShiftRightOp Operand ShiftCount Target
    TRY(ensure_opcode(Opcode::DefShiftRight));
    
    auto operand_0 = TRY(parse_operand());
    auto shift_count_1 = TRY(parse_shift_count());
    auto target_2 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefShiftRight) + operand_0->get_size() + shift_count_1->get_size() + target_2->get_size();
    auto payload_size = 0;

    auto self = new ShiftRight(full_size, payload_size);

    return self;
}
