// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_mod() {
    // DefMod := ModOp Dividend Divisor Target
    TRY(ensure_opcode(Opcode::DefMod));
    
    auto dividend_0 = TRY(parse_dividend());
    auto divisor_1 = TRY(parse_divisor());
    auto target_2 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefMod) + dividend_0->get_size() + divisor_1->get_size() + target_2->get_size();
    auto payload_size = 0;

    auto self = new Mod(full_size, payload_size);

    return self;
}
