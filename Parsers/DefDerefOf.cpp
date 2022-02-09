// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_deref_of() {
    // DefDerefOf := DerefOfOp ObjReference
    TRY(ensure_opcode(Opcode::DefDerefOf));
    
    auto obj_reference_0 = TRY(parse_obj_reference());

    auto full_size = opcode_length(Opcode::DefDerefOf) + obj_reference_0->get_size();
    auto payload_size = 0;

    auto self = new DerefOf(full_size, payload_size);

    return self;
}
