// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "NameString.h"

NameString::NameString(const std::string& string) {
    m_strings.push_back(string);
    m_size = string.size();
}

void NameString::print(int depth) {
    indent(depth * 2);
    if(m_strings.size() == 1)
        fmt::print("- NameString: {}\n", m_strings[0]);

    if(m_strings.size() == 2)
        fmt::print("- NameString: {}.{}\n", m_strings[0], m_strings[1]);
}

std::string NameString::value_string() {
    std::string result;
    for(const auto str: m_strings) {
        result.append(str);
    }
    return result;
}

void NameString::append_string(const std::string& string) {
    m_strings.push_back(string);
    m_size += string.size();
//    fmt::print("Appending {}, size = {}\n", string, m_size);
}

