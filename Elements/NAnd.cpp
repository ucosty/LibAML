// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "NAnd.h"

void NAnd::print(int depth) {
    indent(depth * 2);
    fmt::print("- NAnd\n");
}

std::string NAnd::value_string() {
    return "[NAnd]";
}
