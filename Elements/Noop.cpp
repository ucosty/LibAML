// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Noop.h"

void Noop::print(int depth) {
    indent(depth * 2);
    fmt::print("- Noop\n");
}

std::string Noop::value_string() {
    return "[Noop]";
}
