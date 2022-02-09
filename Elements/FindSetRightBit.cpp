// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "FindSetRightBit.h"

void FindSetRightBit::print(int depth) {
    indent(depth * 2);
    fmt::print("- FindSetRightBit\n");
}

std::string FindSetRightBit::value_string() {
    return "[FindSetRightBit]";
}
