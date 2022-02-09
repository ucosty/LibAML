// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Element.h"

class VarPackage : public Element {
ELEMENT_OBJ(ElementType::TermArg)
public:
    VarPackage(size_t size, size_t payload_size) : m_size(size), m_payload_size(payload_size) {}

    [[nodiscard]] std::string value_string() override;
};
