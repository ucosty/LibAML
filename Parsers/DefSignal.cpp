// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_signal() {
    // DefSignal := SignalOp EventObject
    TRY(ensure_opcode(Opcode::DefSignal));
    
    auto event_object_0 = TRY(parse_event_object());

    auto full_size = opcode_length(Opcode::DefSignal) + event_object_0->get_size();
    auto payload_size = 0;

    auto self = new Signal(full_size, payload_size);

    return self;
}
