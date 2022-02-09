// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "And.h"

void And::print(int depth) {
    indent(depth * 2);
    fmt::print("- And\n");
}

std::string And::value_string() {
    return "[And]";
}
