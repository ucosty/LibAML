// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "DataContainer.h"

DataContainer::DataContainer(uint64_t value) {
    type = DataType::QuadWord;
    quadword = value;
}

DataContainer::DataContainer(uint32_t value) {
    type = DataType::DoubleWord;
    quadword = value;
}

DataContainer::DataContainer(uint16_t value) {
    type = DataType::Word;
    quadword = value;
}

DataContainer::DataContainer(uint8_t value) {
    type = DataType::Byte;
    quadword = value;
}

DataContainer::DataContainer(std::string value) {
    type = DataType::String;
    m_string = value;
}
