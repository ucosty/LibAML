// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "ByteReader.h"
#include "Try.h"

ByteReader::ByteReader(uint8_t *bytes, size_t size) : m_bytes(bytes), m_next_byte(bytes), m_size(size) {
    m_end = m_bytes + m_size;
    m_bytes_left = m_size;
}

Result<uint8_t> ByteReader::read_byte() {
    if(m_bytes_left == 0)
        return Lib::Error::from_status(Lib::StatusCode::EndOfFile);
    m_bytes_left--;
    return *m_next_byte++;
}

Result<uint8_t> ByteReader::peek_byte() {
    if(m_bytes_left == 0)
        return Lib::Error::from_status(Lib::StatusCode::EndOfFile);
    return *m_next_byte;
}

Result<uint8_t> ByteReader::peek_byte(size_t offset) {
    if(m_next_byte + offset > m_end)
        return Lib::Error::from_status(Lib::StatusCode::EndOfFile);
    return *(m_next_byte + offset);
}

Result<void> ByteReader::read_bytes(size_t count, uint8_t *output) {
    for (size_t i = 0; i < count; i++)
        *output++ = TRY(read_byte());
    return {};
}

Result<uint16_t> ByteReader::read_word() {
    uint16_t value = 0;
    value |= (uint32_t) TRY(read_byte());
    value |= (uint32_t) TRY(read_byte()) << 8;
    return value;
}

Result<uint16_t> ByteReader::peek_word() {
    uint16_t value = 0;
    value |= (uint32_t) TRY(peek_byte());
    value |= (uint32_t) TRY(peek_byte()) << 8;
    return value;
}

Result<uint32_t> ByteReader::read_dword() {
    uint32_t value = 0;
    value |= (uint32_t) TRY(read_byte());
    value |= (uint32_t) TRY(read_byte()) << 8;
    value |= (uint32_t) TRY(read_byte()) << 16;
    value |= (uint32_t) TRY(read_byte()) << 24;
    return value;
}

Result<uint32_t> ByteReader::peek_dword() {
    uint32_t value = 0;
    value |= (uint32_t) TRY(peek_byte());
    value |= (uint32_t) TRY(peek_byte()) << 8;
    value |= (uint32_t) TRY(peek_byte()) << 16;
    value |= (uint32_t) TRY(peek_byte()) << 24;
    return value;
}

Result<uint64_t> ByteReader::read_qword() {
    uint32_t value = 0;
    value |= (uint64_t) TRY(read_byte());
    value |= (uint64_t) TRY(read_byte()) << 8;
    value |= (uint64_t) TRY(read_byte()) << 16;
    value |= (uint64_t) TRY(read_byte()) << 24;
    value |= (uint64_t) TRY(read_byte()) << 32;
    value |= (uint64_t) TRY(read_byte()) << 40;
    value |= (uint64_t) TRY(read_byte()) << 48;
    value |= (uint64_t) TRY(read_byte()) << 56;
    return value;
}

Result<uint64_t> ByteReader::peek_qword() {
    uint64_t value = 0;
    value |= (uint64_t) TRY(peek_byte());
    value |= (uint64_t) TRY(peek_byte()) << 8;
    value |= (uint64_t) TRY(peek_byte()) << 16;
    value |= (uint64_t) TRY(peek_byte()) << 24;
    value |= (uint64_t) TRY(peek_byte()) << 32;
    value |= (uint64_t) TRY(peek_byte()) << 40;
    value |= (uint64_t) TRY(peek_byte()) << 48;
    value |= (uint64_t) TRY(peek_byte()) << 56;
    return value;
}

void ByteReader::reset() {
    m_next_byte = m_bytes;
}

size_t ByteReader::size() const { return m_size; }

bool ByteReader::is_eof() {
    return m_next_byte == m_end;
}

Result<std::string> ByteReader::read_string() {
    std::string value;
    while (TRY(peek_byte()) != 0)
        value.append(1, (char) TRY(read_byte()));
    TRY(read_byte());
    return value;
}

size_t ByteReader::get_offset() {
    return static_cast<size_t>(m_next_byte - m_bytes);
}

