// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Multiply.h"

void Multiply::print(int depth) {
    indent(depth * 2);
    fmt::print("- Multiply\n");
}

std::string Multiply::value_string() {
    return "[Multiply]";
}
