// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <fstream>
#include <fmt/format-inl.h>
#include "../Library/StringView.h"
#include "../Library/Result.h"
#include "../Library/ByteReader.h"
#include "../Elements/Elements.h"
#include "../Library/Try.h"
#include "../DefinitionBlockHeader.h"
#include "../Opcodes.h"

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

    Result<NameString *> parse_name_string();

    Result<NameString *> parse_name_path();

    Result<NameString *> parse_multi_name_path();

    Result<NameString *> parse_dual_name_path();

    Result<std::string> parse_name_seg();

    Result<char> parse_lead_name_char();

    Result<char> parse_name_char();

    Result<Element *> parse_data();

    Result<Element *> parse_data_ref();

    Result<Element *> parse_scope();

    Result<Element *> parse_sleep();

    Result<Element *> parse_stall();

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

    Result<Element *> parse_while();

    Result<Element *> parse_word_const();

    Result<Element *> parse_double_word_const();

    Result<Element *> parse_quad_word_const();

    Result<Element *> parse_string();

    Result<Element *> parse_arg_obj();

    Result<Element *> parse_local_object();

    Result<Element *> parse_expression_opcode();

    Result<Element *> parse_operand();

    Result<Element *> parse_target();

    Result<Element *> parse_timeout();

    Result<size_t> parse_pkg_length(size_t *consumed);

    Result<Element *> parse_pkg_length();

    Result<Element *> parse_simple_name();

    Result<Element *> parse_super_name();

    Result<void> ensure_opcode(Opcode opcode);

    template<typename F>
    Result<Opcode> ensure_opcode(F &&predicate) {
        auto opcode = TRY(read_next_opcode());
        if (!predicate(opcode)) {
            return Lib::Error::from_code(1);
        }
        return opcode;
    }

    // Generated

    Result<Element *> parse_acquire();

    Result<Element *> parse_add();

    Result<Element *> parse_and();

    Result<Element *> parse_b_c_d_value();

    Result<Element *> parse_byte_list();

    Result<Element *> parse_break();

    Result<Element *> parse_break_point();

    Result<Element *> parse_buf_data();

    Result<Element *> parse_buffer_size();

    Result<Element *> parse_buffer();

    Result<Element *> parse_continue();

    Result<Element *> parse_concat();

    Result<Element *> parse_concat_res();

    Result<Element *> parse_cond_ref_of();

    Result<Element *> parse_copy_object();

    Result<Element *> parse_debug_obj();

    Result<Element *> parse_decrement();

    Result<Element *> parse_deref_of();

    Result<Element *> parse_divide();

    Result<Element *> parse_find_set_left_bit();

    Result<Element *> parse_find_set_right_bit();

    Result<Element *> parse_from_b_c_d();

    Result<Element *> parse_increment();

    Result<Element *> parse_if_else();

    Result<Element *> parse_index();

    Result<Element *> parse_l_and();

    Result<Element *> parse_l_equal();

    Result<Element *> parse_l_greater();

    Result<Element *> parse_l_greater_equal();

    Result<Element *> parse_l_less();

    Result<Element *> parse_l_less_equal();

    Result<Element *> parse_l_not();

    Result<Element *> parse_l_not_equal();

    Result<Element *> parse_load();

    Result<Element *> parse_load_table();

    Result<Element *> parse_l_or();

    Result<Element *> parse_match();

    Result<Element *> parse_mid();

    Result<Element *> parse_mid_obj();

    Result<Element *> parse_mod();

    Result<Element *> parse_mutex_object();

    Result<Element *> parse_multiply();

    Result<Element *> parse_n_and();

    Result<Element *> parse_noop();

    Result<Element *> parse_n_or();

    Result<Element *> parse_not();

    Result<Element *> parse_notify();

    Result<Element *> parse_notify_object();

    Result<Element *> parse_notify_value();

    Result<Element *> parse_obj_reference();

    Result<Element *> parse_object_type();

    Result<Element *> parse_or();

    Result<Element *> parse_package();

    Result<Element *> parse_predicate();

    Result<Element *> parse_var_package();

    Result<Element *> parse_ref_of();

    Result<Element *> parse_release();

    Result<Element *> parse_reference_type_opcode();

    Result<Element *> parse_reset();

    Result<Element *> parse_shift_count();

    Result<Element *> parse_shift_left();

    Result<Element *> parse_shift_right();

    Result<Element *> parse_signal();

    Result<Element *> parse_size_of();

    Result<Element *> parse_store();

    Result<Element *> parse_subtract();

    Result<Element *> parse_timer();

    Result<Element *> parse_to_b_c_d();

    Result<Element *> parse_to_buffer();

    Result<Element *> parse_to_decimal_string();

    Result<Element *> parse_to_hex_string();

    Result<Element *> parse_to_integer();

    Result<Element *> parse_to_string();

    Result<Element *> parse_wait();

    Result<Element *> parse_x_or();

    Result<Element *> parse_divisor();

    Result<Element *> parse_dividend();

    Result<Element *> parse_remainder();

    Result<Element *> parse_quotient();

    Result<Element *> parse_msec_time();

    Result<Element *> parse_event_object();

    Result<Element *> parse_search_pkg();

    Result<Element *> parse_match_opcode();

    Result<Element *> parse_start_index();

    Result<Element *> parse_fatal();

    Result<Element *> parse_fatal_type();

    Result<Element *> parse_fatal_code();

    Result<Element *> parse_fatal_arg();

    Result<Element *> parse_index_value();

    Result<Element *> parse_buff_pkg_str_obj();

    Result<Element *> parse_num_elements();

    Result<Element *> parse_package_element_list();

    Result<Element *> parse_data_ref_object();

    Result<Element *> parse_integer();

    Result<Element *> parse_object_reference();

    Result<Element *> parse_var_num_elements();

    Result<Element *> parse_length_arg();

    Result<Element *> parse_else();

    Result<Element *> parse_usec_time();

private:
    std::vector<uint8_t> m_bytes;
    ByteReader m_byte_reader{};
};
