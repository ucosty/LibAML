// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// Dividend := TermArg => Integer
Result<Element *> Parser::parse_dividend() {
    return parse_term_arg();
}
