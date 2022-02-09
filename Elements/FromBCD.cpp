// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "FromBCD.h"

void FromBCD::print(int depth) {
    indent(depth * 2);
    fmt::print("- FromBCD\n");
}

std::string FromBCD::value_string() {
    return "[FromBCD]";
}
