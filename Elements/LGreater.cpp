// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "LGreater.h"

void LGreater::print(int depth) {
    indent(depth * 2);
    fmt::print("- LGreater\n");
}

std::string LGreater::value_string() {
    return "[LGreater]";
}
