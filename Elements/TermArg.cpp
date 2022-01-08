// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "TermArg.h"

void TermArg::print(int depth) {
    indent(depth * 2);
    fmt::print("- TermArg\n");
}

std::string TermArg::value_string() {
    return "[term-arg]";
}
