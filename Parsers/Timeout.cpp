// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// Timeout := WordData
Result<Element *> Parser::parse_timeout() {
    return parse_integer();
}
