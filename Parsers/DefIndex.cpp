// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefIndex := IndexOp BuffPkgStrObj IndexValue Target
Result<Element *> Parser::parse_index() {
    TRY(ensure_opcode(Opcode::DefIndex));

    auto buff_pkg_str_obj_0 = TRY(parse_buff_pkg_str_obj());
    auto index_value_1 = TRY(parse_index_value());
    auto target_2 = TRY(parse_target());

    auto full_size = opcode_length(Opcode::DefIndex) + buff_pkg_str_obj_0->get_size() + index_value_1->get_size() +
                     target_2->get_size();
    auto payload_size = 0;

    auto self = new Index(full_size, payload_size);

    return self;
}
