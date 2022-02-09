// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Not.h"

void Not::print(int depth) {
    indent(depth * 2);
    fmt::print("- Not\n");
}

std::string Not::value_string() {
    return "[Not]";
}
