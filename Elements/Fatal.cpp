// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Fatal.h"

void Fatal::print(int depth) {
    indent(depth * 2);
    fmt::print("- Fatal\n");
}

std::string Fatal::value_string() {
    return "[Fatal]";
}
