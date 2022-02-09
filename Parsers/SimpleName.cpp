// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_simple_name() {
    auto name_object_or_error = parse_name_string();
    if(!name_object_or_error.is_error()) {
        return name_object_or_error.get();
    }

    auto arg_object_or_error = parse_arg_object();
    if(!arg_object_or_error.is_error()) {
        return arg_object_or_error.get();
    }

    return TRY(parse_local_object());
}
