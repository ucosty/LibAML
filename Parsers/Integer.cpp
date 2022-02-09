// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// Integer := DecimalConst | OctalConst | HexConst
Result<Element *> Parser::parse_integer() {
    return parse_term_arg();
}
