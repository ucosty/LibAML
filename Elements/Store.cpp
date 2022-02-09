// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Store.h"

void Store::print(int depth) {
    indent(depth * 2);
    fmt::print("- Store\n");
}

std::string Store::value_string() {
    return "[Store]";
}
