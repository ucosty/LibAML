// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_load_table() {
    // DefLoadTable := LoadTableOp TermArg TermArg TermArg TermArg TermArg TermArg
    TRY(ensure_opcode(Opcode::DefLoadTable));
    
    auto term_arg_0 = TRY(parse_term_arg());
    auto term_arg_1 = TRY(parse_term_arg());
    auto term_arg_2 = TRY(parse_term_arg());
    auto term_arg_3 = TRY(parse_term_arg());
    auto term_arg_4 = TRY(parse_term_arg());
    auto term_arg_5 = TRY(parse_term_arg());

    auto full_size = opcode_length(Opcode::DefLoadTable) + term_arg_0->get_size() + term_arg_1->get_size() + term_arg_2->get_size() + term_arg_3->get_size() + term_arg_4->get_size() + term_arg_5->get_size();
    auto payload_size = 0;

    auto self = new LoadTable(full_size, payload_size);

    return self;
}
