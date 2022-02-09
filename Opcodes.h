// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "Library/Types.h"
#include <string_view>

enum OpcodeMultibyte : uint8_t {
    ExtOpPrefix = 0x5B,
    LnotOp = 0x92,
};

#define EXT_OPCODE(code) ((code) | (0x5B << 8))
#define LAND_OPCODE(code) ((code) | (0x90 << 8))
#define LNOT_OPCODE(code) ((code) | (0x92 << 8))

enum class Opcode {
    DefAlias = 0x06,
    DefName = 0x08,
    DefScope = 0x10,
    DefBankField = EXT_OPCODE(0x87),
    DefCreateBitField = 0x8d,
    DefCreateByteField = 0x8c,
    DefCreateDWordField = 0x8a,
    DefCreateField = EXT_OPCODE(0x13),
    DefCreateQWordField = 0x8f,
    DefCreateWordField = 0x8b,
    DefDataRegion = EXT_OPCODE(0x88),
    DefExternal = 0x15,
    DefOpRegion = EXT_OPCODE(0x80),
    DefPowerRes = EXT_OPCODE(0x84),
    DefThermalZone = EXT_OPCODE(0x85),
    DefLoad = EXT_OPCODE(0x20),
    DefAcquire = EXT_OPCODE(0x23),
    DefAdd = 0x72,
    DefAnd = 0x7b,
    DefBuffer = 0x11,
    DefConcat = 0x43,
    DefConcatRes = 0x84,
    DefCondRefOf = EXT_OPCODE(0x12),
    DefCopyObject = 0x9d,
    DefDecrement = 0x76,
    DefDerefOf = 0x83,
    DefDivide = 0x78,
    DefFindSetLeftBit = 0x81,
    DefFindSetRightBit = 0x82,
    DefFromBCD = EXT_OPCODE(0x28),
    DefIncrement = 0x75,
    DefIndex = 0x88,
    DefLAnd = 0x90,
    DefLEqual = 0x93,
    DefLGreater = 0x94,
    DefLGreaterEqual = LNOT_OPCODE(0x95),
    DefLLess = 0x95,
    DefLLessEqual = LNOT_OPCODE(0x94),
    DefMid = 0x9e,
    DefLNot = 0x92,
    DefLNotEqual = LNOT_OPCODE(0x93),
    DefLoadTable = EXT_OPCODE(0x1f),
    DefLOr = 0x91,
    DefMatch = 0x89,
    DefMod = 0x85,
    DefMultiply = 0x77,
    DefNAnd = 0x7c,
    DefNOr = 0x7e,
    DefNot = 0x80,
    DefObjectType = 0x8e,
    DefOr = 0x7d,
    DefPackage = 0x12,
    DefVarPackage = 0x13,
    DefRefOf = 0x71,
    DefShiftLeft = 0x79,
    DefShiftRight = 0x7a,
    DefSizeOf = 0x87,
    DefStore = 0x70,
    DefSubtract = 0x74,
    DefTimer = EXT_OPCODE(0x33),
    DefToBCD = EXT_OPCODE(0x29),
    DefToBuffer = 0x96,
    DefToDecimalString = 0x97,
    DefToHexString = 0x98,
    DefToInteger = 0x99,
    DefToString = 0x9c,
    DefWait = EXT_OPCODE(0x25),
    DefXOr = 0x7f,
//    MethodInvocation = 0x14,
    DefMethod = 0x14,
    DefBreak = 0xa5,
    DefBreakPoint = 0xcc,
    DefContinue = 0x9f,
    DefFatal = EXT_OPCODE(0x32),
    DefIfElse = 0xA0,
    DefElse = 0xA1,
    DefNoop = 0xa3,
    DefNotify = 0x86,
    DefRelease = EXT_OPCODE(0x27),
    DefReset = EXT_OPCODE(0x26),
    DefReturn = 0xa4,
    DefSignal = EXT_OPCODE(0x24),
    DefSleep = EXT_OPCODE(0x22),
    DefStall = EXT_OPCODE(0x21),
    DefWhile = 0xa2,
    RevisionOp = EXT_OPCODE(0x30),
    ByteConst = 0x0a,
    WordConst = 0x0b,
    DWordConst = 0x0c,
    QWordConst = 0x0e,
    String = 0x0d,
    ZeroOp = 0x00,
    OneOp = 0x01,
    OnesOp = 0xff,
    DefDevice = EXT_OPCODE(0x82),
    DualNamePrefix = 0x2e,
    MultiNamePrefix = 0x2f,
    Local0Op = 0x60,
    Local1Op = 0x61,
    Local2Op = 0x62,
    Local3Op = 0x63,
    Local4Op = 0x64,
    Local5Op = 0x65,
    Local6Op = 0x66,
    Local7Op = 0x67,
    Arg0Op = 0x68,
    Arg1Op = 0x69,
    Arg2Op = 0x6A,
    Arg3Op = 0x6B,
    Arg4Op = 0x6C,
    Arg5Op = 0x6D,
    Arg6Op = 0x6E,
    DebugOp = EXT_OPCODE(0x31),
};

size_t opcode_length(Opcode opcode);

std::string_view to_string(Opcode opcode);

bool is_object(Opcode opcode);

bool is_term_object(Opcode opcode);

bool is_namespace_modifier_object(Opcode opcode);

bool is_named_object(Opcode opcode);

bool is_statement_opcode(Opcode opcode);

bool is_expression_opcode(Opcode opcode);

bool is_digit_char(uint8_t value);

bool is_name_char(uint8_t value);

bool is_root_char(uint8_t value);

bool is_data_ref_object(Opcode opcode);

bool is_data_object(Opcode opcode);

bool is_object_reference(Opcode opcode);

bool has_prefix_path(uint8_t value);

bool is_null_name(uint8_t value);

bool is_multi_name_path(uint8_t value);

bool is_dual_name_path(uint8_t value);

bool is_lead_name_char(uint8_t value);

bool is_term_arg(Opcode opcode);

bool is_computational_data(Opcode opcode);

bool is_const_obj(Opcode opcode);

bool is_package_element(Opcode opcode);

bool is_arg_obj(Opcode opcode);

bool is_local_object(Opcode opcode);
