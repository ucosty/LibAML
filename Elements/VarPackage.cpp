// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "VarPackage.h"

void VarPackage::print(int depth) {
    indent(depth * 2);
    fmt::print("- VarPackage\n");
}

std::string VarPackage::value_string() {
    return "[VarPackage]";
}
