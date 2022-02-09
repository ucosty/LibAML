// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Stall.h"

void Stall::print(int depth) {
    indent(depth * 2);
    fmt::print("- Stall\n");
}

std::string Stall::value_string() {
    return "[Stall]";
}
