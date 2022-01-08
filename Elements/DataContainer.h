// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <fmt/format-inl.h>
#include <string>

enum class DataType {
    None,
    Byte,
    Word,
    DoubleWord,
    QuadWord,
    String,
};

class DataContainer {
public:
    DataContainer() : type(DataType::None), quadword(0) {}

    explicit DataContainer(uint64_t value);

    explicit DataContainer(uint8_t value);

    explicit DataContainer(uint16_t value);

    explicit DataContainer(uint32_t value);

    explicit DataContainer(std::string value);

    DataType type;

    template<typename T>
    [[nodiscard]] T get() const {
        switch (type) {
            case DataType::None:
                return 0;
            case DataType::Byte:
                return byte;
            case DataType::Word:
                return word;
            case DataType::DoubleWord:
                return doubleword;
            case DataType::QuadWord:
                return quadword;
        }
        return 0;
    }

    [[nodiscard]] std::string get_string() const {
        return m_string;
    }

    [[nodiscard]] size_t get_size() {
        switch (type) {
            case DataType::None:
                return 0;
            case DataType::Byte:
                return 1;
            case DataType::Word:
                return 2;
            case DataType::DoubleWord:
                return 4;
            case DataType::QuadWord:
                return 8;
            case DataType::String:
                return m_string.length() + 1;
        }
        return 0;
    }

private:
    std::string m_string;
    union {
        uint64_t quadword;
        uint32_t doubleword;
        uint16_t word;
        uint8_t byte;
    };
};

template<>
struct fmt::formatter<DataContainer> {
    static constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const DataContainer container, FormatContext &ctx) {
        switch (container.type) {
            case DataType::None:
                return format_to(ctx.out(), "[none]");
            case DataType::Byte:
                return format_to(ctx.out(), "{:#0x}", container.get<uint8_t>());
            case DataType::Word:
                return format_to(ctx.out(), "{:#0x}", container.get<uint16_t>());
            case DataType::DoubleWord:
                return format_to(ctx.out(), "{:#0x}", container.get<uint32_t>());
            case DataType::QuadWord:
                return format_to(ctx.out(), "{:#0x}", container.get<uint64_t>());
            case DataType::String:
                return format_to(ctx.out(), "{}", container.get_string());
        }
        return format_to(ctx.out(), "[unknown]");

    }
};