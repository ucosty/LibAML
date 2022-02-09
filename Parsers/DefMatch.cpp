// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_match() {
    // DefMatch := MatchOp SearchPkg MatchOpcode Operand MatchOpcode Operand StartIndex
    TRY(ensure_opcode(Opcode::DefMatch));
    
    auto search_pkg_0 = TRY(parse_search_pkg());
    auto match_opcode_1 = TRY(parse_match_opcode());
    auto operand_2 = TRY(parse_operand());
    auto match_opcode_3 = TRY(parse_match_opcode());
    auto operand_4 = TRY(parse_operand());
    auto start_index_5 = TRY(parse_start_index());

    auto full_size = opcode_length(Opcode::DefMatch) + search_pkg_0->get_size() + match_opcode_1->get_size() + operand_2->get_size() + match_opcode_3->get_size() + operand_4->get_size() + start_index_5->get_size();
    auto payload_size = 0;

    auto self = new Match(full_size, payload_size);

    return self;
}
