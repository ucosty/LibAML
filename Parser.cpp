// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Parser.h"

Result<DefinitionBlock> Parser::parse_header() {
    auto definition_block_header = DefinitionBlockHeader{};
    definition_block_header.signature = TRY(parse_magic("DSDT"_sv));
    definition_block_header.length = TRY(m_byte_reader.read_dword());
    definition_block_header.compliance_revision = TRY(m_byte_reader.read_byte());
    definition_block_header.checksum = TRY(m_byte_reader.read_byte());
    TRY(m_byte_reader.read_bytes(6, reinterpret_cast<uint8_t *>(definition_block_header.oem_id)));
    TRY(m_byte_reader.read_bytes(8, reinterpret_cast<uint8_t *>(definition_block_header.oem_table_id)));
    definition_block_header.oem_revision = TRY(m_byte_reader.read_dword());
    definition_block_header.asl_compiler_id = TRY(m_byte_reader.read_dword());
    definition_block_header.asl_compiler_revision = TRY(m_byte_reader.read_dword());

    auto payload_size = definition_block_header.length - sizeof(DefinitionBlockHeader);
    return DefinitionBlock(definition_block_header.length, payload_size);
}

Result<void> Parser::ensure_opcode(Opcode opcode) {
    auto opcode_byte = static_cast<uint16_t>(TRY(m_byte_reader.read_byte()));
    if (opcode_byte == OpcodeMultibyte::ExtOpPrefix || opcode_byte == OpcodeMultibyte::LnotOp) {
        opcode_byte = (opcode_byte << 8) | TRY(m_byte_reader.read_byte());
    }
    if (static_cast<Opcode>(opcode_byte) != opcode) {
        fmt::print("Error: Invalid opcode {}, expected {}\n", opcode_byte, opcode);
        return Lib::Error::from_code(1);
    }
    return {};
}

Result<void> Parser::parse_term_list(Element *parent) {
//    fmt::print(" + Opening {}: size = {}, payload_size = {}\n", type_name(parent->get_type()), parent->get_size(),
//               parent->get_payload_size());
    auto bytes_remaining = TRY(parse_term_list(parent, parent->get_payload_size()));
//    fmt::print(" + Closing {}: bytes_remaining = {}\n", type_name(parent->get_type()), bytes_remaining);
    return {};
}

Result<size_t> Parser::parse_term_list(Element *parent, size_t bytes_remaining) {
    auto opcode = TRY(peek_next_opcode());
    if (is_term_object(opcode)) {
        auto child = TRY(delegate_parser(opcode));

//        fmt::print("\t+ {}: parent = {}, child_size = {}, bytes_remaining = {}, after_append = {}\n",
//                   type_name(child->get_type()), type_name(parent->get_type()), child->get_size(), bytes_remaining,
//                   bytes_remaining - child->get_size());

        parent->add_child(child);

        if (child->get_size() > bytes_remaining) {
            fmt::print("PANIC: child_size > bytes_remaining!\n");
            return Lib::Error::from_code(1);
        }
        if (bytes_remaining - child->get_size() > 0) {
            parse_term_list(parent, bytes_remaining - child->get_size());
        }
    }

    return bytes_remaining;
}


Result<DefinitionBlock> Parser::parse() {
    auto root_element = TRY(parse_header());
    TRY(parse_term_list(&root_element));
    root_element.print(0);

    if (m_byte_reader.bytes_left() > 0) {
        fmt::print("Unread bytes: {}\n", m_byte_reader.bytes_left());
    }
    return root_element;
}

Result<Opcode> Parser::peek_next_opcode() {
    auto opcode_byte = static_cast<uint16_t>(TRY(m_byte_reader.peek_byte()));
    if (opcode_byte == OpcodeMultibyte::ExtOpPrefix || opcode_byte == OpcodeMultibyte::LnotOp) {
        opcode_byte = (opcode_byte << 8) | TRY(m_byte_reader.peek_byte(1));
    }
    return static_cast<Opcode>(opcode_byte);
}

Result<Opcode> Parser::read_next_opcode() {
    auto opcode_byte = static_cast<uint16_t>(TRY(m_byte_reader.read_byte()));
    if (opcode_byte == OpcodeMultibyte::ExtOpPrefix || opcode_byte == OpcodeMultibyte::LnotOp) {
        opcode_byte = (opcode_byte << 8) | TRY(m_byte_reader.read_byte());
    }
    return static_cast<Opcode>(opcode_byte);
}

Result<Element *> Parser::delegate_parser(Opcode opcode) {
    switch (opcode) {
        case Opcode::DefName:
            return parse_name();
        case Opcode::DefScope:
            return parse_scope();
        case Opcode::DefDevice:
            return parse_device();
        case Opcode::DefMethod:
            return parse_method();
        case Opcode::DefReturn:
            return parse_return();
        default:
            fmt::print("Unknown opcode: {:x} at offset {}, bytes left = {}, byte = {:0x}\n", opcode,
                       m_byte_reader.get_offset(), m_byte_reader.bytes_left(), TRY(m_byte_reader.peek_byte()));
    }
    return Lib::Error::from_code(1);
}

Result<Element *> Parser::parse_name() {
    // DefName := NameOp NameString DataRefObject
    TRY(ensure_opcode(Opcode::DefName));
    auto name_string = TRY(parse_name_string());
    auto data_ref = TRY(parse_data_ref());
    auto self = new Name(opcode_length(Opcode::DefName) + data_ref->get_size() + name_string->get_size());
    self->add_metadata(Metadata::StringConst, name_string);
    self->add_metadata(Metadata::ObjectRef, data_ref);

//    fmt::print("Name: name = {}, string_size = {}, data_size = {}, total_size = {}\n", name_string->value_string(),
//               name_string->get_size(), data_ref->get_size(),
//               opcode_length(Opcode::DefName) + data_ref->get_size() + name_string->get_size());

    return self;

}

Result<NameString *> Parser::parse_name_string() {
    // NameString := <RootChar namepath> | <PrefixPath namepath>
    // NameString := <RootChar | PrefixPath | Nothing> namepath

    auto lead_byte = TRY(m_byte_reader.peek_byte());
    if (is_root_char(lead_byte)) {
        TRY(m_byte_reader.read_byte());
    }
    if (has_prefix_path(lead_byte)) {
        TRY(m_byte_reader.read_byte());
    }

    return parse_name_path();
}

Result<NameString *> Parser::parse_name_path() {
    // NamePath := NameSeg | DualNamePath | MultiNamePath | NullName
    auto lead_byte = TRY(m_byte_reader.peek_byte());
    if (is_null_name(lead_byte)) {
        TRY(m_byte_reader.read_byte());
//        TRY(ensure_opcode(Opcode::ZeroOp));
        return new NameString("");
    }
    if (is_multi_name_path(lead_byte)) {
        return parse_multi_name_path();
    }
    if (is_dual_name_path(lead_byte)) {
        return parse_dual_name_path();
    }
    if (is_lead_name_char(lead_byte)) {
        return new NameString(TRY(parse_name_seg()));
    }
    return Lib::Error::from_code(1);
}

Result<NameString *> Parser::parse_multi_name_path() {
    // MultiNamePath := MultiNamePrefix SegCount NameSeg(SegCount)
    TRY(ensure_opcode(Opcode::MultiNamePrefix));
    auto segment_count = TRY(m_byte_reader.read_byte());
    auto self = new NameString(opcode_length(Opcode::MultiNamePrefix));
    for (uint8_t i = 0; i < segment_count; i++) {
        self->append_string(TRY(parse_name_seg()));
    }
    return self;
}

Result<NameString *> Parser::parse_dual_name_path() {
    // DualNamePath := DualNamePrefix NameSeg NameSeg
    TRY(ensure_opcode(Opcode::DualNamePrefix));
    auto self = new NameString(opcode_length(Opcode::DualNamePrefix));
    self->append_string(TRY(parse_name_seg()));
    self->append_string(TRY(parse_name_seg()));
    return self;
}

Result<std::string> Parser::parse_name_seg() {
    // NameSeg := <leadnamechar namechar namechar namechar>
    char value[5]{0}; // Extra char for null termination
    value[0] = TRY(parse_lead_name_char());
    value[1] = TRY(parse_name_char());
    value[2] = TRY(parse_name_char());
    value[3] = TRY(parse_name_char());
    return std::string(value);
}

Result<char> Parser::parse_lead_name_char() {
    char value = TRY(m_byte_reader.read_byte());
    if (!is_lead_name_char(value))
        return Lib::Error::from_code(1);
    return value;
}

Result<char> Parser::parse_name_char() {
    char value = TRY(m_byte_reader.read_byte());
    if (!is_name_char(value))
        return Lib::Error::from_code(1);
    return value;
}

Result<Element *> Parser::parse_data_ref() {
    auto opcode = TRY(ensure_opcode(is_data_ref_object));

    switch (opcode) {
        case Opcode::ByteConst: {
            auto value = TRY(m_byte_reader.read_byte());
            return new Data(value);
        }
        case Opcode::WordConst: {
            auto value = TRY(m_byte_reader.read_word());
            return new Data(value);
        }
        case Opcode::DWordConst: {
            auto value = TRY(m_byte_reader.read_dword());
            return new Data(value);
        }
        case Opcode::QWordConst: {
            auto value = TRY(m_byte_reader.read_qword());
            return new Data(value);
        }
        case Opcode::String: {
            auto value = TRY(m_byte_reader.read_string());
            return new Data(value);
        }
    }
    return Lib::Error::from_code(1);
}

Result<Element *> Parser::parse_scope() {
    // DefScope := ScopeOp PkgLength NameString TermList
    TRY(ensure_opcode(Opcode::DefScope));
    size_t package_length_size = 0;
    auto package_length = TRY(get_package_length(&package_length_size));
    auto name = TRY(parse_name_string());
    auto full_size = package_length + opcode_length(Opcode::DefScope);
    auto payload_size = package_length - package_length_size - name->get_size();
    auto self = new Scope(full_size, payload_size);
//    fmt::print("Scope: name = {}, full_size = {}, payload_size = {}\n", name->value_string(), full_size, payload_size);
    self->add_metadata(Metadata::Name, name);
    if (self->get_payload_size() > 0) {
        TRY(parse_term_list(self));
    }
    return self;
}

Result<Element *> Parser::parse_device() {
    TRY(ensure_opcode(Opcode::DefDevice));
    size_t package_length_size = 0;
    auto package_length = TRY(get_package_length(&package_length_size));
    auto name = TRY(parse_name_string());

    auto full_size = package_length + opcode_length(Opcode::DefDevice);
    auto payload_size = package_length - package_length_size - name->get_size();

//    fmt::print("Device: package_length = {}, name = {}, full_size = {}, payload_size = {}\n", package_length, name->value_string(), full_size, payload_size);

    auto self = new Device(full_size, payload_size);
    self->add_metadata(Metadata::Name, name);
//    TRY(parse_term_list(self));
    return self;
}

Result<Element *> Parser::parse_method() {
    // DefMethod := MethodOp PkgLength NameString MethodFlags TermList
    TRY(ensure_opcode(Opcode::DefMethod));
    size_t package_length_size = 0;
    auto package_length = TRY(get_package_length(&package_length_size));
    auto name = TRY(parse_name_string());
    auto flags = TRY(m_byte_reader.read_byte());
    auto full_size = package_length + opcode_length(Opcode::DefMethod);
    auto payload_size = package_length - package_length_size - name->get_size() - sizeof(flags);

    fmt::print("Method: package_length = {}, name = {}, full_size = {}, payload_size = {}\n", package_length,
               name->value_string(), full_size, payload_size);

    auto self = new Method(full_size, payload_size);
    self->add_metadata(Metadata::Name, name);
    if (payload_size > 0) {
        TRY(parse_term_list(self));
    }
    return self;
}

Result<Element *> Parser::parse_return() {
    // DefReturn := ReturnOp ArgObject
    TRY(ensure_opcode(Opcode::DefReturn));
    auto arg_object = TRY(parse_arg_object());
    auto size = opcode_length(Opcode::DefReturn) + arg_object->get_size();
    fmt::print("Return: package_length = {}\n", size);
    auto self = new Return(size);
    self->add_child(arg_object);
    return self;
}

Result<Element *> Parser::parse_arg_object() {
    // ArgObject := TermArg => DataRefObject
    // Term => Evaluated Type
    // Shows the resulting type of the evaluation of Term.
    return parse_term_arg();
}

Result<Element *> Parser::parse_term_arg() {
    // TermArg := ExpressionOpcode | DataObject | ArgObj | LocalObj
    auto next_opcode = TRY(peek_next_opcode());
    if(is_arg_obj(next_opcode)) {
        return parse_arg_obj();
    }
    if(is_local_object(next_opcode)) {
        return parse_local_object();
    }
    if(is_data_object(next_opcode)) {
        return parse_data_object();
    }
    if(is_expression_opcode(next_opcode)) {
        return parse_expression_opcode();
    }
    return Lib::Error::from_code(1);
}

Result<Element *> Parser::parse_computational_data() {
    // ComputationalData := ByteConst | WordConst | DWordConst | QWordConst | String | ConstObj | RevisionOp | DefBuffer
    auto next_opcode = TRY(peek_next_opcode());
    switch (next_opcode) {
        case Opcode::ByteConst:
            return parse_byte_const();
        case Opcode::WordConst:
            return parse_word_const();
        case Opcode::DWordConst:
            return parse_double_word_const();
        case Opcode::QWordConst:
            return parse_quad_word_const();
        case Opcode::String:
            return parse_string();
        case Opcode::ZeroOp:
            return new Data((uint8_t) 0);
        case Opcode::OneOp:
            return new Data((uint8_t) 1);
        case Opcode::OnesOp:
            return new Data((uint8_t) 0xff);
        case Opcode::RevisionOp:
            return parse_revision_op();
        case Opcode::DefBuffer:
            return parse_def_buffer();
    }
    return nullptr;
}

Result<Element *> Parser::parse_data_object() {
    // DataObject := ComputationalData | DefPackage | DefVarPackage
    auto next_opcode = TRY(peek_next_opcode());
    if (is_computational_data(next_opcode)) {
        return parse_computational_data();
    }
    if (next_opcode == Opcode::DefPackage) {
        return parse_def_package();
    }
    if (next_opcode == Opcode::DefVarPackage) {
        return parse_def_var_package();
    }
    return Lib::Error::from_code(1);
}

Result<Element *> Parser::parse_def_package() {
    // DefPackage := PackageOp PkgLength NumElements PackageElementList
    TRY(ensure_opcode(Opcode::DefPackage));

    size_t package_length_size = 0;
    auto package_length = TRY(get_package_length(&package_length_size));
    auto num_elements = TRY(m_byte_reader.read_byte());

    for(int i = 0; i < num_elements; i++) {
        TRY(parse_package_element());
    }
    return nullptr;
}

Result<Element *> Parser::parse_package_element() {
    return nullptr;
}

Result<Element *> Parser::parse_def_var_package() {
    // DefVarPackage := VarPackageOp PkgLength VarNumElements PackageElementList
    TRY(ensure_opcode(Opcode::DefVarPackage));

    return nullptr;
}

Result<Element *> Parser::parse_revision_op() {
    // FIXME: what is this for?
    TRY(ensure_opcode(Opcode::RevisionOp));
    return new Data((uint8_t) 0);
}

Result<Element *> Parser::parse_def_buffer() {
    // DefBuffer := BufferOp PkgLength BufferSize ByteList
    TRY(ensure_opcode(Opcode::DefBuffer));
    return nullptr;
}

Result<Element *> Parser::parse_byte_const() {
    TRY(ensure_opcode(Opcode::ByteConst));
    auto value = TRY(m_byte_reader.read_byte());
    return new Data(value);
}

Result<Element *> Parser::parse_word_const() {
    TRY(ensure_opcode(Opcode::WordConst));
    auto value = TRY(m_byte_reader.read_word());
    return new Data(value);
}

Result<Element *> Parser::parse_double_word_const() {
    TRY(ensure_opcode(Opcode::DWordConst));
    auto value = TRY(m_byte_reader.read_dword());
    return new Data(value);
}

Result<Element *> Parser::parse_quad_word_const() {
    TRY(ensure_opcode(Opcode::QWordConst));
    auto value = TRY(m_byte_reader.read_qword());
    return new Data(value);
}

Result<Element *> Parser::parse_string() {
    TRY(ensure_opcode(Opcode::String));
    auto value = TRY(m_byte_reader.read_string());
    return new Data(value);
}

Result<Element *> Parser::parse_arg_obj() {
    return nullptr;
}

Result<Element *> Parser::parse_local_object() {
    return nullptr;
}

Result<Element *> Parser::parse_expression_opcode() {
    return nullptr;
}

Result<size_t> Parser::get_package_length(size_t *consumed) {
    // <bit 7-6: bytedata count that follows (0-3)>
    // <bit 5-4: only used if pkglength < 63>
    // <bit 3-0: least significant package length nybble>
    auto lead_byte = TRY(m_byte_reader.read_byte());
    auto byte_count = (lead_byte >> 6) & 0x03u;
    *consumed = byte_count + 1;
    switch (byte_count) {
        case 0:
            return lead_byte;
        case 1: {
            auto byte_data_1 = TRY(m_byte_reader.read_byte());
            return (lead_byte & 0xf) | (byte_data_1 << 4);
        }
        case 2: {
            auto byte_data_1 = TRY(m_byte_reader.read_byte());
            auto byte_data_2 = TRY(m_byte_reader.read_byte());
            return (lead_byte & 0xf) | (byte_data_1 << 4) | (byte_data_2 << 12);
        }
        case 3: {
            auto byte_data_1 = TRY(m_byte_reader.read_byte());
            auto byte_data_2 = TRY(m_byte_reader.read_byte());
            auto byte_data_3 = TRY(m_byte_reader.read_byte());
            return (lead_byte & 0xf) | (byte_data_1 << 4) | (byte_data_2 << 12) | (byte_data_3 << 20);
        }
        default:
            return Lib::Error::from_code(1);
    }
}
