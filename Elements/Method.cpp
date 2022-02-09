// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "DefMethod.h"

void Method::print(int depth) {
    indent(depth * 2);
    fmt::print("- Method: {{ name = {}, children = {} }}\n", m_metadata[Metadata::Name]->value_string(), m_children.size());
    Element::print(depth + 1);
}
