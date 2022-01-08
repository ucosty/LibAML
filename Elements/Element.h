// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <vector>
#include <unordered_map>
#include "../Library/UniquePtr.h"
#include "ElementTypes.h"
#include "../Opcodes.h"
#include "../Library/StringView.h"
#include "DataContainer.h"

void indent(int depth);

enum class Metadata {
    Name,
    StringConst,
    ObjectRef
};

class Element {
public:
    Element() = default;
    Element(size_t size, size_t payload_size) : m_size(size), m_payload_size(payload_size) {}

    void add_child(Element *element_ptr);

    void print();

    virtual void print(int depth);

    virtual DataContainer value();

    virtual std::string value_string();

    virtual size_t get_size() const;

    virtual size_t get_payload_size () const;

    size_t child_count();

    void add_metadata(Metadata metadata, Element *element);

    virtual ElementType get_type() const { return ElementType::Element; }

protected:
    std::vector<Element *> m_children;
    std::unordered_map<Metadata, Element *> m_metadata;
    size_t m_size{0};
    size_t m_payload_size{0};
};

#define ELEMENT_OBJ(TYPE) \
    public:               \
    void print(int depth) override; \
    [[nodiscard]] size_t get_size() const override { return m_size; } \
    [[nodiscard]] size_t get_payload_size() const override { return m_payload_size; } \
    ElementType get_type() const override { return (TYPE); } \
    private: \
    size_t m_size{0}; \
    size_t m_payload_size{0};
