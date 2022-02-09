// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "CopyObject.h"

void CopyObject::print(int depth) {
    indent(depth * 2);
    fmt::print("- CopyObject\n");
}

std::string CopyObject::value_string() {
    return "[CopyObject]";
}
