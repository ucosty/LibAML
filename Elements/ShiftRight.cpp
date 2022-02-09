// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ShiftRight.h"

void ShiftRight::print(int depth) {
    indent(depth * 2);
    fmt::print("- ShiftRight\n");
}

std::string ShiftRight::value_string() {
    return "[ShiftRight]";
}
