// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ConcatRes.h"

void ConcatRes::print(int depth) {
    indent(depth * 2);
    fmt::print("- ConcatRes\n");
}

std::string ConcatRes::value_string() {
    return "[ConcatRes]";
}
