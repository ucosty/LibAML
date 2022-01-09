// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <fstream>
#include <fmt/format-inl.h>
#include "Library/StringView.h"
#include "Library/Result.h"
#include "Library/ByteReader.h"
#include "Elements/Elements.h"
#include "Library/Try.h"
#include "DefinitionBlockHeader.h"
#include "Opcodes.h"

class Parser {
public:
    Parser() = default;

    void read_file(const char *filename) {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);
        m_bytes.resize(size, 0);
        file.read(reinterpret_cast<char *>(m_bytes.data()), size);
        file.close();
        m_byte_reader = ByteReader(m_bytes.data(), size);
    }

    Result<uint32_t> parse_magic(const Lib::StringView &expected) {
        auto value = m_byte_reader.read_dword();
        Lib::StringView magic{reinterpret_cast<const char *>(&value), 4};
        if (magic != expected) {
            return Lib::Error::from_code(1);
        }
        return value;
    }

    Result<void> peek_next() {
        auto next_byte = TRY(m_byte_reader.peek_byte());
        fmt::print("next_byte = {:#04x}\n", next_byte);
        return {};
    }

    Result<Opcode> read_next_opcode();

    Result<Opcode> peek_next_opcode();

    Result<void> parse_term_list(Element *parent);

    Result<size_t> parse_term_list(Element *parent, size_t bytes_remaining);

    Result<DefinitionBlock> parse_header();

    Result<DefinitionBlock> parse();

    Result<Element *> delegate_parser(Opcode opcode);

    Result<Element *> parse_name();

//    Result<NameString *> old_parse_name_string();

    Result<NameString *> parse_name_string();

    Result<NameString *> parse_name_path();

    Result<NameString *> parse_multi_name_path();

    Result<NameString *> parse_dual_name_path();

    Result<std::string> parse_name_seg();

    Result<char> parse_lead_name_char();

    Result<char> parse_name_char();

    Result<Element *> parse_data_ref();

    Result<Element *> parse_scope();

    Result<Element *> parse_device();

    Result<Element *> parse_method();

    Result<Element *> parse_return();

    Result<Element *> parse_arg_object();

    Result<Element *> parse_term_arg();

    Result<Element *> parse_computational_data();

    Result<Element *> parse_data_object();

    Result<Element *> parse_def_package();

    Result<Element *> parse_def_var_package();

    Result<Element *> parse_package_element();

    Result<Element *> parse_revision_op();

    Result<Element *> parse_def_buffer();

    Result<Element *> parse_byte_const();

    Result<Element *> parse_word_const();

    Result<Element *> parse_double_word_const();

    Result<Element *> parse_quad_word_const();

    Result<Element *> parse_string();

    Result<Opcode> parse_arg_obj();

    Result<Opcode> parse_local_object();

    Result<Element *> parse_expression_opcode();

    Result<size_t> get_package_length(size_t *consumed);

    Result<void> ensure_opcode(Opcode opcode);

    template<typename F>
    Result<Opcode> ensure_opcode(F &&predicate) {
        auto opcode = TRY(read_next_opcode());
        if (!predicate(opcode)) {
            return Lib::Error::from_code(1);
        }
        return opcode;
    }

private:
    std::vector<uint8_t> m_bytes;
    ByteReader m_byte_reader{};
};
