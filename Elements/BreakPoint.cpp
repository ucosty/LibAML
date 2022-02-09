// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "BreakPoint.h"

void BreakPoint::print(int depth) {
    indent(depth * 2);
    fmt::print("- BreakPoint\n");
}

std::string BreakPoint::value_string() {
    return "[BreakPoint]";
}
