// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_from_b_c_d() {
    // DefFromBCD := FromBcdOp BCDValue Target
    TRY(ensure_opcode(Opcode::DefFromBCD));
    
    auto b_c_d_value_0 = TRY(parse_b_c_d_value());
    auto target_1 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefFromBCD) + b_c_d_value_0->get_size() + target_1->get_size();
    auto payload_size = 0;

    auto self = new FromBCD(full_size, payload_size);

    return self;
}
