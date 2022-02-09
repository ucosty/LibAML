// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ArgObject.h"

void ArgObject::print(int depth) {
    indent(depth * 2);
    fmt::print("- ArgObject\n");
}

std::string ArgObject::value_string() {
    return "[ArgObject]";
}
