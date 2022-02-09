// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "While.h"

void While::print(int depth) {
    indent(depth * 2);
    fmt::print("- While\n");
}

std::string While::value_string() {
    return "[While]";
}
