// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

// DefDevice := DeviceOp PkgLength NameString TermList
Result<Element *> Parser::parse_device() {
    TRY(ensure_opcode(Opcode::DefDevice));
    size_t package_length_size = 0;
    auto package_length = TRY(parse_pkg_length(&package_length_size));
    auto name = TRY(parse_name_string());

    auto full_size = package_length + opcode_length(Opcode::DefDevice);
    auto payload_size = package_length - package_length_size - name->get_size();

    auto self = new Device(full_size, payload_size);
    self->add_metadata(Metadata::Name, name);
    TRY(parse_term_list(self));
    return self;
}
