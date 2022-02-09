// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefWhile := WhileOp PkgLength Predicate TermList
Result<Element *> Parser::parse_while() {
    TRY(ensure_opcode(Opcode::DefWhile));

    size_t package_length_size = 0;
    auto package_length = TRY(parse_pkg_length(&package_length_size));
    auto predicate_1 = TRY(parse_predicate());
    auto full_size = opcode_length(Opcode::DefWhile) + package_length_size + predicate_1->get_size();
    auto self = new While(full_size, package_length);
    TRY(parse_term_list(self));
    return self;
}
