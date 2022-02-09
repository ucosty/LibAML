// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Reset.h"

void Reset::print(int depth) {
    indent(depth * 2);
    fmt::print("- Reset\n");
}

std::string Reset::value_string() {
    return "[Reset]";
}
