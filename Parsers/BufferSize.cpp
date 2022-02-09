// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// BufferSize := TermArg => Integer
Result<Element *> Parser::parse_buffer_size() {
    return parse_term_arg();
}
