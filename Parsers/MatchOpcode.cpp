// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// MatchOpcode := ByteData
Result<Element *> Parser::parse_match_opcode() {
    auto value = TRY(m_byte_reader.read_byte());
    return new Data(value);
}
// 0 MTR
// 1 MEQ
// 2 MLE
// 3 MLT
// 4 MGE
// 5 MGT
