// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_concat() {
    // DefConcat := ConcatOp Data Data Target
    TRY(ensure_opcode(Opcode::DefConcat));
    
    auto data_0 = TRY(parse_data());
    auto data_1 = TRY(parse_data());
    auto target_2 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefConcat) + data_0->get_size() + data_1->get_size() + target_2->get_size();
    auto payload_size = 0;

    auto self = new Concat(full_size, payload_size);

    return self;
}
