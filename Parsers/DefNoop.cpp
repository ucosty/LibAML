// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_noop() {
    // DefNoop := NoopOp
    TRY(ensure_opcode(Opcode::DefNoop));

    auto full_size = opcode_length(Opcode::DefNoop);
    auto payload_size = 0;

    auto self = new Noop(full_size, payload_size);

    return self;
}
