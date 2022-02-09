#pragma once

#include "Element.h"

class PkgLength : public Element {
ELEMENT_OBJ(ElementType::Device)
public:
    PkgLength(size_t size, size_t pkg_length) : m_size(size), m_pkg_length(pkg_length) {}

private:
    size_t m_pkg_length;
};
