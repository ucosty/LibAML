// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Or.h"

void Or::print(int depth) {
    indent(depth * 2);
    fmt::print("- Or\n");
}

std::string Or::value_string() {
    return "[Or]";
}
