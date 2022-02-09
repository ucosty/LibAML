// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// PackageElementList := Nothing | <packageelement packageelementlist>
Result<Element *> Parser::parse_package_element_list() {
    return parse_package_element();
}
