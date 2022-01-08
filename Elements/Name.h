// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Element.h"

class Name : public Element {
ELEMENT_OBJ(ElementType::Name)
public:
    Name(size_t size) : m_size(size) {}
};
