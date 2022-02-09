// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_notify() {
    // DefNotify := NotifyOp NotifyObject NotifyValue
    TRY(ensure_opcode(Opcode::DefNotify));
    
    auto notify_object_0 = TRY(parse_notify_object());
    auto notify_value_1 = TRY(parse_notify_value());

    auto full_size = opcode_length(Opcode::DefNotify) + notify_object_0->get_size() + notify_value_1->get_size();
    auto payload_size = 0;

    auto self = new Notify(full_size, payload_size);

    return self;
}
