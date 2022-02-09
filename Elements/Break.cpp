// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Break.h"

void Break::print(int depth) {
    indent(depth * 2);
    fmt::print("- Break\n");
}

std::string Break::value_string() {
    return "[Break]";
}
