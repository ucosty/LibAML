// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// FatalType := ByteData
Result<Element *> Parser::parse_fatal_type() {
    auto value = TRY(m_byte_reader.read_byte());
    return new Data(value);
}
