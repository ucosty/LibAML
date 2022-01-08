// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Element.h"

class Data : public Element {
ELEMENT_OBJ(ElementType::Data)
public:
    explicit Data(uint64_t value) : m_value(value), m_size(8 + opcode_length(Opcode::QWordConst)) {}

    explicit Data(uint32_t value) : m_value(value), m_size(4 + opcode_length(Opcode::DWordConst)) {}

    explicit Data(uint16_t value) : m_value(value), m_size(2 + opcode_length(Opcode::WordConst)) {}

    explicit Data(uint8_t value) : m_value(value), m_size(1 + opcode_length(Opcode::ByteConst)) {}

    explicit Data(std::string value) : m_value(std::move(value)) {
        m_size = m_value.get_size() + opcode_length(Opcode::String);
    }

    DataContainer value() override;

private:
    DataContainer m_value;
};