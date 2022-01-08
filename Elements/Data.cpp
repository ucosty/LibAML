// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Data.h"

void Data::print(int depth) {
    indent(depth * 2);
    fmt::print("- Data: value = {}\n", m_value);
}

DataContainer Data::value() {
    return m_value;
}
