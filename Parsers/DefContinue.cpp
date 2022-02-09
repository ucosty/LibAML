// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_continue() {
    // DefContinue := ContinueOp
    TRY(ensure_opcode(Opcode::DefContinue));

    auto full_size = opcode_length(Opcode::DefContinue);
    auto payload_size = 0;

    auto self = new Continue(full_size, payload_size);

    return self;
}
