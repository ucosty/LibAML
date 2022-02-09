// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// Divisor := TermArg => Integer
Result<Element *> Parser::parse_divisor() {
    return parse_term_arg();
}
