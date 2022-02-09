// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ToInteger.h"

void ToInteger::print(int depth) {
    indent(depth * 2);
    fmt::print("- ToInteger\n");
}

std::string ToInteger::value_string() {
    return "[ToInteger]";
}
