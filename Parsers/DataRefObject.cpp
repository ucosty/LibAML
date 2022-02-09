// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DataRefObject := DataObject | ObjectReference>
Result<Element *> Parser::parse_data_ref_object() {
    auto data_object_or_error = parse_data_object();
    if(!data_object_or_error.is_error()) {
        return data_object_or_error.get();
    }
    return parse_object_reference();
}
