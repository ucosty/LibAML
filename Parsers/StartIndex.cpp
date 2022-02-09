// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// StartIndex := TermArg => Integer
Result<Element *> Parser::parse_start_index() {
    return parse_term_arg();
}
