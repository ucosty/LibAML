// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// ReferenceTypeOpcode := DefRefOf | DefDerefOf | DefIndex | UserTermObj
Result<Element *> Parser::parse_reference_type_opcode() {
    TRY(ensure_opcode(Opcode::DebugOp));
    return new Element{opcode_length(Opcode::DebugOp), 0};
}
