// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Mod.h"

void Mod::print(int depth) {
    indent(depth * 2);
    fmt::print("- Mod\n");
}

std::string Mod::value_string() {
    return "[Mod]";
}
