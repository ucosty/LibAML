// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LLess.h"

void LLess::print(int depth) {
    indent(depth * 2);
    fmt::print("- LLess\n");
}

std::string LLess::value_string() {
    return "[LLess]";
}
