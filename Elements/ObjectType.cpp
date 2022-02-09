// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ObjectType.h"

void ObjectType::print(int depth) {
    indent(depth * 2);
    fmt::print("- ObjectType\n");
}

std::string ObjectType::value_string() {
    return "[ObjectType]";
}
