// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LEqual.h"

void LEqual::print(int depth) {
    indent(depth * 2);
    fmt::print("- LEqual\n");
}

std::string LEqual::value_string() {
    return "[LEqual]";
}
