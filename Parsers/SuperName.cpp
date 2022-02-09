// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// SuperName := SimpleName | DebugObj | ReferenceTypeOpcode
Result<Element *> Parser::parse_super_name() {
    auto simple_name_or_error = parse_simple_name();
    if(!simple_name_or_error.is_error()) {
        return simple_name_or_error.get();
    }

    auto debug_obj_or_error = parse_debug_obj();
    if(!debug_obj_or_error.is_error()) {
        return debug_obj_or_error.get();
    }

    return TRY(parse_reference_type_opcode());
}
