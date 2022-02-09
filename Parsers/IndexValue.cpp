// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// IndexValue := TermArg => Integer
Result<Element *> Parser::parse_index_value() {
    return parse_term_arg();
}
