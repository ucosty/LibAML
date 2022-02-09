// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefElse := ElseOp PkgLength TermList
Result<Element *> Parser::parse_else() {
    TRY(ensure_opcode(Opcode::DefElse));
    size_t package_length_size = 0;
    auto package_length = TRY(parse_pkg_length(&package_length_size));
    auto full_size = opcode_length(Opcode::DefElse) + package_length_size;
    auto self = new Else(full_size, package_length);
    TRY(parse_term_list(self));
    return self;
}
