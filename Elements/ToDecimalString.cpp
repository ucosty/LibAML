// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ToDecimalString.h"

void ToDecimalString::print(int depth) {
    indent(depth * 2);
    fmt::print("- ToDecimalString\n");
}

std::string ToDecimalString::value_string() {
    return "[ToDecimalString]";
}
