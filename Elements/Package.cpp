// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Package.h"

void Package::print(int depth) {
    indent(depth * 2);
    fmt::print("- Package\n");
}

std::string Package::value_string() {
    return "[Package]";
}
