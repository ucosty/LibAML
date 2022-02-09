// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LoadTable.h"

void LoadTable::print(int depth) {
    indent(depth * 2);
    fmt::print("- LoadTable\n");
}

std::string LoadTable::value_string() {
    return "[LoadTable]";
}
