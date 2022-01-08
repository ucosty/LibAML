// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Element.h"

class NameString : public Element {
ELEMENT_OBJ(ElementType::NameString)
public:
    explicit NameString(const std::string& string);
    explicit NameString(size_t initial_size) : m_size(initial_size) {}

    NameString() = default;

    [[nodiscard]] std::string value_string() override;

    void append_string(const std::string& string);

private:
    std::vector<std::string> m_strings;
};


