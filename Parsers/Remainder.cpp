// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// Remainder := Target
Result<Element *> Parser::parse_remainder() {
    return parse_target();
}
