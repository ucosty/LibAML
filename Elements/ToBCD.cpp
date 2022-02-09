// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ToBCD.h"

void ToBCD::print(int depth) {
    indent(depth * 2);
    fmt::print("- ToBCD\n");
}

std::string ToBCD::value_string() {
    return "[ToBCD]";
}
