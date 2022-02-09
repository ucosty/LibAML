// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include <fmt/format-inl.h>
#include "Parsers/Parser.h"

int main() {
    Parser parser;
//    parser.read_file("Data/acpi-dsdt.aml");
    parser.read_file("Data/test.aml");
    auto result = parser.parse();
    if (result.is_error()) {
        fmt::print("Fatal: got error {}\n", result.get_error().get_code());
    }

    return 0;
}
