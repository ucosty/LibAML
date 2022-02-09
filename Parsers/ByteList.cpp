// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// ByteList := Nothing | <bytedata bytelist>
Result<Element *> Parser::parse_byte_list() {
    return parse_term_arg();
}