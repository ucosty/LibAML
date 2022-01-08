// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Return.h"

void Return::print(int depth) {
    indent(depth * 2);
    fmt::print("- Return: term_arg = {}\n", m_children[0]->value_string());
}
