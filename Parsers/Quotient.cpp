// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// Quotient := Target
Result<Element *> Parser::parse_quotient() {
    return parse_target();
}
