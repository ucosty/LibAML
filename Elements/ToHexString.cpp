// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ToHexString.h"

void ToHexString::print(int depth) {
    indent(depth * 2);
    fmt::print("- ToHexString\n");
}

std::string ToHexString::value_string() {
    return "[ToHexString]";
}
