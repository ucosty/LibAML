// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_break() {
    // DefBreak := BreakOp
    TRY(ensure_opcode(Opcode::DefBreak));

    auto full_size = opcode_length(Opcode::DefBreak);
    auto payload_size = 0;

    auto self = new Break(full_size, payload_size);

    return self;
}
