// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Mid.h"

void Mid::print(int depth) {
    indent(depth * 2);
    fmt::print("- Mid\n");
}

std::string Mid::value_string() {
    return "[Mid]";
}
