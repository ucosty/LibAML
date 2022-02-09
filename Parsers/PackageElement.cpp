// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// PackageElement := DataRefObject | NameString>
Result<Element *> Parser::parse_package_element() {
    auto data_ref_object_or_error = parse_data_ref();
    return nullptr;
}
