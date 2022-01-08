// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Types.h"
#include "Result.h"
#include <string>

class ByteReader {
public:
    ByteReader() = default;

    ByteReader(uint8_t *bytes, size_t size);

    Result<uint8_t> read_byte();

    Result<uint8_t> peek_byte();

    Result<uint8_t> peek_byte(size_t offset);

    Result<void> read_bytes(size_t count, uint8_t *output);

    Result<uint16_t> read_word();

    Result<uint16_t> peek_word();

    Result<uint32_t> read_dword();

    Result<uint32_t> peek_dword();

    Result<uint64_t> read_qword();

    Result<uint64_t> peek_qword();

    Result<std::string> read_string();

    size_t get_offset();

    void reset();

    bool is_eof();

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t bytes_left() const { return m_bytes_left; };

private:
    uint8_t *m_bytes{nullptr};
    uint8_t *m_next_byte{nullptr};
    uint8_t *m_end{nullptr};
    size_t m_size{0};
    size_t m_bytes_left{0};
};
