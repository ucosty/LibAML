// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "IfElse.h"

void IfElse::print(int depth) {
    indent(depth * 2);
    fmt::print("- IfElse\n");
}

std::string IfElse::value_string() {
    return "[IfElse]";
}
