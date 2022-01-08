// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <utility>

#include "Element.h"
#include "NameString.h"

class Scope : public Element {
ELEMENT_OBJ(ElementType::Scope)
public:
    explicit Scope(size_t size, size_t payload_size) : m_size(size), m_payload_size(payload_size) {}
};
