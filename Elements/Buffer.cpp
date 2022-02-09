// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Buffer.h"

void Buffer::print(int depth) {
    indent(depth * 2);
    fmt::print("- Buffer\n");
}

std::string Buffer::value_string() {
    return "[Buffer]";
}
