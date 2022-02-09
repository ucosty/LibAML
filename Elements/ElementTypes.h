// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

enum class ElementType {
    Undefined,
    Element,
    DefinitionBlock,
    Scope,
    Device,
    Name,
    NameString,
    Data,
    Method,
    TermArg,
    ArgObject,
    Acquire
};

static const char *type_name(ElementType type) {
    switch(type) {
        case ElementType::Undefined:
            return "Undefined";
        case ElementType::Element:
            return "Element";
        case ElementType::DefinitionBlock:
            return "DefinitionBlock";
        case ElementType::Scope:
            return "Scope";
        case ElementType::Device:
            return "Device";
        case ElementType::Name:
            return "Name";
        case ElementType::NameString:
            return "NameString";
        default:
            return "Unknown";
    }
}