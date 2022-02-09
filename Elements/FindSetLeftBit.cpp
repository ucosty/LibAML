// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "FindSetLeftBit.h"

void FindSetLeftBit::print(int depth) {
    indent(depth * 2);
    fmt::print("- FindSetLeftBit\n");
}

std::string FindSetLeftBit::value_string() {
    return "[FindSetLeftBit]";
}
