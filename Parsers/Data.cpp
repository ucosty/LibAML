// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// Data := TermArg => ComputationalData
Result<Element *> Parser::parse_data() {
    return parse_term_arg();
}
