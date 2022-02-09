// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LOr.h"

void LOr::print(int depth) {
    indent(depth * 2);
    fmt::print("- LOr\n");
}

std::string LOr::value_string() {
    return "[LOr]";
}
