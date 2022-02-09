// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// BuffPkgStrObj := TermArg => Buffer | Package | String
Result<Element *> Parser::parse_buff_pkg_str_obj() {
    return parse_term_arg();
}
