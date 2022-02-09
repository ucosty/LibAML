// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_load() {
    // DefLoad := LoadOp NameString Target
    TRY(ensure_opcode(Opcode::DefLoad));
    
    auto name_string_0 = TRY(parse_name_string());
    auto target_1 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefLoad) + name_string_0->get_size() + target_1->get_size();
    auto payload_size = 0;

    auto self = new Load(full_size, payload_size);

    return self;
}
