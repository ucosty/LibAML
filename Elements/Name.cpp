// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Name.h"

void Name::print(int depth) {
    indent(depth * 2);
    fmt::print("- Name: {{ string = {}, object_ref = {} }}\n"
               , m_metadata[Metadata::StringConst]->value_string()
               , m_metadata[Metadata::ObjectRef]->value());
    Element::print(depth + 1);
}
