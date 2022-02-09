// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Concat.h"

void Concat::print(int depth) {
    indent(depth * 2);
    fmt::print("- Concat\n");
}

std::string Concat::value_string() {
    return "[Concat]";
}
