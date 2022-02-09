// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_cond_ref_of() {
    // DefCondRefOf := CondRefOfOp SuperName Target
    TRY(ensure_opcode(Opcode::DefCondRefOf));
    
    auto super_name_0 = TRY(parse_super_name());
    auto target_1 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefCondRefOf) + super_name_0->get_size() + target_1->get_size();
    auto payload_size = 0;

    auto self = new CondRefOf(full_size, payload_size);

    return self;
}
