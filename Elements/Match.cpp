// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Match.h"

void Match::print(int depth) {
    indent(depth * 2);
    fmt::print("- Match\n");
}

std::string Match::value_string() {
    return "[Match]";
}
