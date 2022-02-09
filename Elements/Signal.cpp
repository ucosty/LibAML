// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Signal.h"

void Signal::print(int depth) {
    indent(depth * 2);
    fmt::print("- Signal\n");
}

std::string Signal::value_string() {
    return "[Signal]";
}
