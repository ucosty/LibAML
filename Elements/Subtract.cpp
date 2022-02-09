// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Subtract.h"

void Subtract::print(int depth) {
    indent(depth * 2);
    fmt::print("- Subtract\n");
}

std::string Subtract::value_string() {
    return "[Subtract]";
}
