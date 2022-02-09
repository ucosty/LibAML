// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_release() {
    // DefRelease := ReleaseOp MutexObject
    TRY(ensure_opcode(Opcode::DefRelease));
    
    auto mutex_object_0 = TRY(parse_mutex_object());

    auto full_size = opcode_length(Opcode::DefRelease) + mutex_object_0->get_size();
    auto payload_size = 0;

    auto self = new Release(full_size, payload_size);

    return self;
}
