// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_to_string() {
    // DefToString := ToStringOp TermArg LengthArg Target
    TRY(ensure_opcode(Opcode::DefToString));
    
    auto term_arg_0 = TRY(parse_term_arg());
    auto length_arg_1 = TRY(parse_length_arg());
    auto target_2 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefToString) + term_arg_0->get_size() + length_arg_1->get_size() + target_2->get_size();
    auto payload_size = 0;

    auto self = new ToString(full_size, payload_size);

    return self;
}
