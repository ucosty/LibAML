// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_wait() {
    // DefWait := WaitOp EventObject Operand
    TRY(ensure_opcode(Opcode::DefWait));
    
    auto event_object_0 = TRY(parse_event_object());
    auto operand_1 = TRY(parse_operand());

    auto full_size = opcode_length(Opcode::DefWait) + event_object_0->get_size() + operand_1->get_size();
    auto payload_size = 0;

    auto self = new Wait(full_size, payload_size);

    return self;
}
