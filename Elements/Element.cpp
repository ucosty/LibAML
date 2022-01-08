// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include <fmt/format-inl.h>
#include "Element.h"

void indent(int depth) {
    for (int i = 0; i < depth; i++)
        putchar(' ');
}

void Element::add_child(Element *element_ptr) {
    m_children.push_back(element_ptr);
}

void Element::print() {
    print(0);
}

void Element::print(int depth) {
    for (const auto &child: m_children)
        child->print(depth);
}

std::string Element::value_string() {
    return "";
}

DataContainer Element::value() {
    return {};
}

size_t Element::child_count() {
    return m_children.size();
}

void Element::add_metadata(Metadata metadata, Element *element) {
    m_metadata[metadata] = element;
}

size_t Element::get_size() const {
    return m_size;
}

size_t Element::get_payload_size() const {
    return m_payload_size;
}
