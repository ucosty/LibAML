// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// NumElements := ByteData
Result<Element *> Parser::parse_num_elements() {
    auto value = TRY(m_byte_reader.read_byte());
    return new Data(value);
}
