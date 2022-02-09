// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Increment.h"

void Increment::print(int depth) {
    indent(depth * 2);
    fmt::print("- Increment\n");
}

std::string Increment::value_string() {
    return "[Increment]";
}
