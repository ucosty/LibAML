// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LGreaterEqual.h"

void LGreaterEqual::print(int depth) {
    indent(depth * 2);
    fmt::print("- LGreaterEqual\n");
}

std::string LGreaterEqual::value_string() {
    return "[LGreaterEqual]";
}
