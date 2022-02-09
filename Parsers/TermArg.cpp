// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// TermArg := ExpressionOpcode | DataObject | ArgObj | LocalObj
Result<Element *> Parser::parse_term_arg() {
    auto next_opcode = TRY(peek_next_opcode());
    if (is_arg_obj(next_opcode)) {
        return parse_arg_obj();
    }
    if (is_local_object(next_opcode)) {
        return parse_local_object();
    }
    if (is_data_object(next_opcode)) {
        return parse_data_object();
    }
    if (is_expression_opcode(next_opcode)) {
        return parse_expression_opcode();
    }
    return Lib::Error::from_code(1);
}
