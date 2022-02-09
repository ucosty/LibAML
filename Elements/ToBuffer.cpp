// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ToBuffer.h"

void ToBuffer::print(int depth) {
    indent(depth * 2);
    fmt::print("- ToBuffer\n");
}

std::string ToBuffer::value_string() {
    return "[ToBuffer]";
}
