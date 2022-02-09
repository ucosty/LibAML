// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ShiftLeft.h"

void ShiftLeft::print(int depth) {
    indent(depth * 2);
    fmt::print("- ShiftLeft\n");
}

std::string ShiftLeft::value_string() {
    return "[ShiftLeft]";
}
