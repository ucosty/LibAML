// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LLessEqual.h"

void LLessEqual::print(int depth) {
    indent(depth * 2);
    fmt::print("- LLessEqual\n");
}

std::string LLessEqual::value_string() {
    return "[LLessEqual]";
}
