// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// ObjReference := TermArg => ObjectReference | String
Result<Element *> Parser::parse_obj_reference() {
    return parse_term_arg();
}
