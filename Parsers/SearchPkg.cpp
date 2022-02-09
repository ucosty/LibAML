// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// SearchPkg := TermArg => Package
Result<Element *> Parser::parse_search_pkg() {
    return parse_term_arg();
}
