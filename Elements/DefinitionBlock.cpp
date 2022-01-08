// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "DefinitionBlock.h"

void DefinitionBlock::print(int depth) {
    indent(depth * 2);
    fmt::print("- DefinitionBlock: size = {}\n", m_size);
    Element::print(depth + 1);
}

