// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "DerefOf.h"

void DerefOf::print(int depth) {
    indent(depth * 2);
    fmt::print("- DerefOf\n");
}

std::string DerefOf::value_string() {
    return "[DerefOf]";
}
