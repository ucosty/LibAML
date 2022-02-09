// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "PkgLength.h"

void PkgLength::print(int depth) {
    indent(depth * 2);
    fmt::print("- PkgLength\n");
}
