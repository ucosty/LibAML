// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Load.h"

void Load::print(int depth) {
    indent(depth * 2);
    fmt::print("- Load\n");
}

std::string Load::value_string() {
    return "[Load]";
}
