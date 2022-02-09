// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_store() {
    // DefStore := StoreOp TermArg SuperName
    TRY(ensure_opcode(Opcode::DefStore));
    
    auto term_arg_0 = TRY(parse_term_arg());
    auto super_name_1 = TRY(parse_super_name());

    auto full_size = opcode_length(Opcode::DefStore) + term_arg_0->get_size() + super_name_1->get_size();
    auto payload_size = 0;

    auto self = new Store(full_size, payload_size);

    return self;
}
