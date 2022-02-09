// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// MidObj := TermArg => Buffer | String
Result<Element *> Parser::parse_mid_obj() {
    return parse_target();
}
