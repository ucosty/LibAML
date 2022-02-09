// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefIf := IfOp PkgLength Predicate TermList DefElse
Result<Element *> Parser::parse_if_else() {
    TRY(ensure_opcode(Opcode::DefIfElse));

    size_t package_length_size = 0;
    auto package_length = TRY(parse_pkg_length(&package_length_size));
    auto predicate_1 = TRY(parse_predicate());
    auto full_size = opcode_length(Opcode::DefIfElse) + package_length_size + predicate_1->get_size();
    auto self = new IfElse(full_size, package_length);
    TRY(parse_term_list(self));
    auto else_2 = TRY(parse_else());
    return self;
}
