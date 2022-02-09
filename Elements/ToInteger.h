// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Element.h"

class ToInteger : public Element {
ELEMENT_OBJ(ElementType::TermArg)
public:
    ToInteger(size_t size, size_t payload_size) : m_size(size), m_payload_size(payload_size) {}

    [[nodiscard]] std::string value_string() override;
};
