// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_stall() {
    // DefStall := StallOp UsecTime
    TRY(ensure_opcode(Opcode::DefStall));
    
    auto usec_time_0 = TRY(parse_usec_time());

    auto full_size = opcode_length(Opcode::DefStall) + usec_time_0->get_size();
    auto payload_size = 0;

    auto self = new Stall(full_size, payload_size);

    return self;
}
