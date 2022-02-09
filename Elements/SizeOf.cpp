// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "SizeOf.h"

void SizeOf::print(int depth) {
    indent(depth * 2);
    fmt::print("- SizeOf\n");
}

std::string SizeOf::value_string() {
    return "[SizeOf]";
}
