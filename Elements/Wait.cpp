// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Wait.h"

void Wait::print(int depth) {
    indent(depth * 2);
    fmt::print("- Wait\n");
}

std::string Wait::value_string() {
    return "[Wait]";
}
