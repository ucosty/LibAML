// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Divide.h"

void Divide::print(int depth) {
    indent(depth * 2);
    fmt::print("- Divide\n");
}

std::string Divide::value_string() {
    return "[Divide]";
}
