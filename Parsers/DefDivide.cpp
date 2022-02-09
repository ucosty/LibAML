// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_divide() {
    // DefDivide := DivideOp Dividend Divisor Remainder Quotient
    TRY(ensure_opcode(Opcode::DefDivide));
    
    auto dividend_0 = TRY(parse_dividend());
    auto divisor_1 = TRY(parse_divisor());
    auto remainder_2 = TRY(parse_remainder());
    auto quotient_3 = TRY(parse_quotient());

    auto full_size = opcode_length(Opcode::DefDivide) + dividend_0->get_size() + divisor_1->get_size() + remainder_2->get_size() + quotient_3->get_size();
    auto payload_size = 0;

    auto self = new Divide(full_size, payload_size);

    return self;
}
