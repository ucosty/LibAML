// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DebugObj := DebugOp
Result<Element *> Parser::parse_debug_obj() {
    TRY(ensure_opcode(Opcode::DebugOp));
    return new Element{opcode_length(Opcode::DebugOp), 0};
}
