// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_copy_object() {
    // DefCopyObject := CopyObjectOp TermArg SimpleName
    TRY(ensure_opcode(Opcode::DefCopyObject));
    
    auto term_arg_0 = TRY(parse_term_arg());
    auto simple_name_1 = TRY(parse_simple_name());

    auto full_size = opcode_length(Opcode::DefCopyObject) + term_arg_0->get_size() + simple_name_1->get_size();
    auto payload_size = 0;

    auto self = new CopyObject(full_size, payload_size);

    return self;
}
