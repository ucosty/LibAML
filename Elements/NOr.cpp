// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "NOr.h"

void NOr::print(int depth) {
    indent(depth * 2);
    fmt::print("- NOr\n");
}

std::string NOr::value_string() {
    return "[NOr]";
}
