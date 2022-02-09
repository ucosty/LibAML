// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Notify.h"

void Notify::print(int depth) {
    indent(depth * 2);
    fmt::print("- Notify\n");
}

std::string Notify::value_string() {
    return "[Notify]";
}
