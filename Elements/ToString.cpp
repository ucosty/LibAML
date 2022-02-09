// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ToString.h"

void ToString::print(int depth) {
    indent(depth * 2);
    fmt::print("- ToString\n");
}

std::string ToString::value_string() {
    return "[ToString]";
}
