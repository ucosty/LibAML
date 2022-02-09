// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// MutexObject := SuperName
Result<Element *> Parser::parse_mutex_object() {
    return parse_super_name();
}
