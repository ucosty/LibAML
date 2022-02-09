// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_sleep() {
    // DefSleep := SleepOp MsecTime
    TRY(ensure_opcode(Opcode::DefSleep));
    
    auto msec_time_0 = TRY(parse_msec_time());

    auto full_size = opcode_length(Opcode::DefSleep) + msec_time_0->get_size();
    auto payload_size = 0;

    auto self = new Sleep(full_size, payload_size);

    return self;
}
