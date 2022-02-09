// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_to_b_c_d() {
    // DefToBCD := ToBcdOp Operand Target
    TRY(ensure_opcode(Opcode::DefToBCD));
    
    auto operand_0 = TRY(parse_operand());
    auto target_1 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefToBCD) + operand_0->get_size() + target_1->get_size();
    auto payload_size = 0;

    auto self = new ToBCD(full_size, payload_size);

    return self;
}
