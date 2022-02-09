// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Sleep.h"

void Sleep::print(int depth) {
    indent(depth * 2);
    fmt::print("- Sleep\n");
}

std::string Sleep::value_string() {
    return "[Sleep]";
}
