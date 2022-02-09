// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Index.h"

void Index::print(int depth) {
    indent(depth * 2);
    fmt::print("- Index\n");
}

std::string Index::value_string() {
    return "[Index]";
}
