// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// ArgObject := TermArg => DataRefObject
Result<Element *> Parser::parse_arg_object() {
    return parse_term_arg();
}
