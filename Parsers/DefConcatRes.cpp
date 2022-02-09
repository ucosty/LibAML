// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_concat_res() {
    // DefConcatRes := ConcatResOp BufData BufData Target
    TRY(ensure_opcode(Opcode::DefConcatRes));
    
    auto buf_data_0 = TRY(parse_buf_data());
    auto buf_data_1 = TRY(parse_buf_data());
    auto target_2 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefConcatRes) + buf_data_0->get_size() + buf_data_1->get_size() + target_2->get_size();
    auto payload_size = 0;

    auto self = new ConcatRes(full_size, payload_size);

    return self;
}
