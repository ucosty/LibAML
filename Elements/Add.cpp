// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Add.h"

void Add::print(int depth) {
    indent(depth * 2);
    fmt::print("- Add\n");
}

std::string Add::value_string() {
    return "[Add]";
}
