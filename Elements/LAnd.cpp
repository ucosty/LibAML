// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LAnd.h"

void LAnd::print(int depth) {
    indent(depth * 2);
    fmt::print("- LAnd\n");
}

std::string LAnd::value_string() {
    return "[LAnd]";
}
