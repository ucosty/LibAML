// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<Element *> Parser::parse_var_package() {
    // DefVarPackage := VarPackageOp PkgLength VarNumElements PackageElementList
    TRY(ensure_opcode(Opcode::DefVarPackage));
    
    size_t package_length_size = 0;
    auto package_length = TRY(parse_pkg_length(&package_length_size));
    auto var_num_elements_1 = TRY(parse_var_num_elements());
    auto package_element_list_2 = TRY(parse_package_element_list());

    auto full_size = opcode_length(Opcode::DefVarPackage) + package_length_size + var_num_elements_1->get_size() + package_element_list_2->get_size();
    auto payload_size = 0;

    auto self = new VarPackage(full_size, payload_size);

    return self;
}
