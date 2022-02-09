// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_mid() {
    // DefMid := MidOp MidObj TermArg TermArg Target
    TRY(ensure_opcode(Opcode::DefMid));
    
    auto mid_obj_0 = TRY(parse_mid_obj());
    auto term_arg_1 = TRY(parse_term_arg());
    auto term_arg_2 = TRY(parse_term_arg());
    auto target_3 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefMid) + mid_obj_0->get_size() + term_arg_1->get_size() + term_arg_2->get_size() + target_3->get_size();
    auto payload_size = 0;

    auto self = new Mid(full_size, payload_size);

    return self;
}
