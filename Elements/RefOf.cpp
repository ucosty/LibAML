// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "RefOf.h"

void RefOf::print(int depth) {
    indent(depth * 2);
    fmt::print("- RefOf\n");
}

std::string RefOf::value_string() {
    return "[RefOf]";
}
