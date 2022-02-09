// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// FatalCode := DWordData
Result<Element *> Parser::parse_fatal_code() {
    auto value = TRY(m_byte_reader.read_dword());
    return new Data(value);
}
