// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Continue.h"

void Continue::print(int depth) {
    indent(depth * 2);
    fmt::print("- Continue\n");
}

std::string Continue::value_string() {
    return "[Continue]";
}
