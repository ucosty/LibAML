// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LNotEqual.h"

void LNotEqual::print(int depth) {
    indent(depth * 2);
    fmt::print("- LNotEqual\n");
}

std::string LNotEqual::value_string() {
    return "[LNotEqual]";
}
