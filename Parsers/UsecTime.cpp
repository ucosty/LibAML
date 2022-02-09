// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// ObjectReference := Integer
Result<Element *> Parser::parse_usec_time() {
    return parse_term_arg();
}
