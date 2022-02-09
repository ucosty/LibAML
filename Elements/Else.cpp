// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Else.h"

void Else::print(int depth) {
    indent(depth * 2);
    fmt::print("- Else\n");
}

std::string Else::value_string() {
    return "[Else]";
}
