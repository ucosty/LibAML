// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

/*
Result<Element *> Parser::parse_return() {
    // DefReturn := ReturnOp ArgObject
    TRY(ensure_opcode(Opcode::DefReturn));
    auto arg_object = TRY(parse_arg_object());
    auto size = opcode_length(Opcode::DefReturn) + arg_object->get_size();
    fmt::print("Return: package_length = {}\n", size);
    auto self = new Return(size, 0);
    self->add_child(arg_object);
    return self;
}
*/

Result<Element *> Parser::parse_return() {
    // DefReturn := ReturnOp ArgObject
    TRY(ensure_opcode(Opcode::DefReturn));
    
    auto arg_object_0 = TRY(parse_arg_object());

    auto full_size = opcode_length(Opcode::DefReturn) + arg_object_0->get_size();
    auto payload_size = 0;

    auto self = new Return(full_size, payload_size);

    return self;
}
