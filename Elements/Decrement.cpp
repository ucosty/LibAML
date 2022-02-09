// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Decrement.h"

void Decrement::print(int depth) {
    indent(depth * 2);
    fmt::print("- Decrement\n");
}

std::string Decrement::value_string() {
    return "[Decrement]";
}
