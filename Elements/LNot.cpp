// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LNot.h"

void LNot::print(int depth) {
    indent(depth * 2);
    fmt::print("- LNot\n");
}

std::string LNot::value_string() {
    return "[LNot]";
}
