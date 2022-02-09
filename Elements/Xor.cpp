// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Xor.h"

void Xor::print(int depth) {
    indent(depth * 2);
    fmt::print("- Xor\n");
}

std::string Xor::value_string() {
    return "[Xor]";
}
