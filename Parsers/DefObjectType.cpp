// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefObjectType := ObjectTypeOp <SimpleName | DebugObj | DefRefOf | DefDerefOf | DefIndex>
Result<Element *> Parser::parse_object_type() {
    TRY(ensure_opcode(Opcode::DefObjectType));

    auto full_size = opcode_length(Opcode::DefObjectType);
    return new ObjectType(full_size, 0);
}
