// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include <fmt/format-inl.h>
#include "DefinitionBlockHeader.h"
#include "Library/StringView.h"

static Lib::StringView string_from_dword(uint32_t *value_ptr) {
    return Lib::StringView{reinterpret_cast<const char *>(value_ptr), 4};
}

void debug_header(DefinitionBlockHeader &definition_block_header) {
    fmt::print("            Signature: {}\n", string_from_dword(&definition_block_header.signature));
    fmt::print("               Length: {}\n", definition_block_header.length);
    fmt::print("             Revision: {}\n", definition_block_header.compliance_revision);
    fmt::print("             Checksum: {}\n", definition_block_header.checksum);
    fmt::print("               OEM ID: {}\n", definition_block_header.oem_id);
    fmt::print("         OEM Table ID: {}\n", definition_block_header.oem_table_id);
    fmt::print("         OEM Revision: {}\n", definition_block_header.oem_revision);
    fmt::print("      ASL Compiler ID: {}\n", string_from_dword(&definition_block_header.asl_compiler_id));
    fmt::print("ASL Compiler Revision: {}\n", definition_block_header.asl_compiler_revision);
}
