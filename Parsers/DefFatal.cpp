// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefFatal := FatalOp FatalType FatalCode FatalArg
Result<Element *> Parser::parse_fatal() {
    TRY(ensure_opcode(Opcode::DefFatal));

    auto fatal_type_0 = TRY(parse_fatal_type());
    auto fatal_code_1 = TRY(parse_fatal_code());
    auto fatal_arg_2 = TRY(parse_fatal_arg());

    auto full_size = opcode_length(Opcode::DefFatal) + fatal_type_0->get_size() + fatal_code_1->get_size() +
                     fatal_arg_2->get_size();
    auto payload_size = 0;

    auto self = new Fatal(full_size, payload_size);

    return self;
}
