// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_break_point() {
    // DefBreakPoint := BreakPointOp
    TRY(ensure_opcode(Opcode::DefBreakPoint));
    


    auto full_size = opcode_length(Opcode::DefBreakPoint);
    auto payload_size = 0;

    auto self = new BreakPoint(full_size, payload_size);

    return self;
}
