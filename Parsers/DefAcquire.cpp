// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefAcquire := AcquireOp MutexObject Timeout
Result<Element *> Parser::parse_acquire() {
    TRY(ensure_opcode(Opcode::DefAcquire));

    auto mutex_object_0 = TRY(parse_mutex_object());
    auto timeout_1 = TRY(parse_timeout());

    auto full_size = opcode_length(Opcode::DefAcquire) + mutex_object_0->get_size() + timeout_1->get_size();
    auto payload_size = 0;

    auto self = new Acquire(full_size, payload_size);

    return self;
}
