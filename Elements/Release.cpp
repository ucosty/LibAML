// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Release.h"

void Release::print(int depth) {
    indent(depth * 2);
    fmt::print("- Release\n");
}

std::string Release::value_string() {
    return "[Release]";
}
