// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "CondRefOf.h"

void CondRefOf::print(int depth) {
    indent(depth * 2);
    fmt::print("- CondRefOf\n");
}

std::string CondRefOf::value_string() {
    return "[CondRefOf]";
}
