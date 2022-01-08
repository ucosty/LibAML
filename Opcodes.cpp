// LibAML
// Copyright (c) 2022 Matthew Costa <ucosty@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
#include "Opcodes.h"

// Object := NameSpaceModifierObj | NamedObj
bool is_object(Opcode opcode) {
    return is_namespace_modifier_object(opcode) || is_named_object(opcode);
}

// TermObj := Object | StatementOpcode | ExpressionOpcode
bool is_term_object(Opcode opcode) {
    return is_object(opcode) || is_statement_opcode(opcode) || is_expression_opcode(opcode);
}

// NameSpaceModifierObj := DefAlias | DefName | DefScope
bool is_namespace_modifier_object(Opcode opcode) {
    switch (opcode) {
        case Opcode::DefAlias:
        case Opcode::DefName:
        case Opcode::DefScope:
            return true;
        default:
            return false;
    }
}

// NamedObj := DefBankField | DefCreateBitField | DefCreateByteField | DefCreateDWordField | DefCreateField | DefCreateQWordField | DefCreateWordField | DefDataRegion | DefExternal | DefOpRegion | DefPowerRes | DefThermalZone
bool is_named_object(Opcode opcode) {
    switch (opcode) {
        case Opcode::DefBankField:
        case Opcode::DefCreateBitField:
        case Opcode::DefCreateByteField:
        case Opcode::DefCreateDWordField:
        case Opcode::DefCreateField:
        case Opcode::DefCreateQWordField:
        case Opcode::DefCreateWordField:
        case Opcode::DefDataRegion:
        case Opcode::DefExternal:
        case Opcode::DefDevice:
        case Opcode::DefOpRegion:
        case Opcode::DefPowerRes:
        case Opcode::DefThermalZone:
        case Opcode::DefMethod:
            return true;
        default:
            return false;
    }
}

// StatementOpcode := DefBreak | DefBreakPoint | DefContinue | DefFatal | DefIfElse | DefNoop | DefNotify |
//                    DefRelease | DefReset | DefReturn | DefSignal | DefSleep | DefStall | DefWhile
bool is_statement_opcode(Opcode opcode) {
    switch (opcode) {
        case Opcode::DefBreak:
        case Opcode::DefBreakPoint:
        case Opcode::DefContinue:
        case Opcode::DefFatal:
        case Opcode::DefIfElse:
        case Opcode::DefNoop:
        case Opcode::DefNotify:
        case Opcode::DefRelease:
        case Opcode::DefReset:
        case Opcode::DefReturn:
        case Opcode::DefSignal:
        case Opcode::DefSleep:
        case Opcode::DefStall:
        case Opcode::DefWhile:
            return true;
        default:
            return false;
    }
}

// ExpressionOpcode := DefAcquire | DefAdd | DefAnd | DefBuffer | DefConcat | DefConcatRes | DefCondRefOf |
//                     DefCopyObject | DefDecrement | DefDerefOf | DefDivide | DefFindSetLeftBit |
//                     DefFindSetRightBit | DefFromBCD | DefIncrement | DefIndex | DefLAnd | DefLEqual |
//                     DefLGreater | DefLGreaterEqual | DefLLess | DefLLessEqual | DefMid | DefLNot |
//                     DefLNotEqual | DefLoadTable | DefLOr | DefMatch | DefMod | DefMultiply | DefNAnd |
//                     DefNOr | DefNot | DefObjectType | DefOr | DefPackage | DefVarPackage | DefRefOf |
//                     DefShiftLeft | DefShiftRight | DefSizeOf | DefStore | DefSubtract | DefTimer |
//                     DefToBCD | DefToBuffer | DefToDecimalString | DefToHexString | DefToInteger |
//                     DefToString | DefWait | DefXOr | MethodInvocation
bool is_expression_opcode(Opcode opcode) {
    switch (opcode) {
        case Opcode::DefAcquire:
        case Opcode::DefAdd:
        case Opcode::DefAnd:
        case Opcode::DefBuffer:
        case Opcode::DefConcat:
        case Opcode::DefConcatRes:
        case Opcode::DefCondRefOf:
        case Opcode::DefCopyObject:
        case Opcode::DefDecrement:
        case Opcode::DefDerefOf:
        case Opcode::DefDivide:
        case Opcode::DefFindSetLeftBit:
        case Opcode::DefFindSetRightBit:
        case Opcode::DefFromBCD:
        case Opcode::DefIncrement:
        case Opcode::DefIndex:
        case Opcode::DefLAnd:
        case Opcode::DefLEqual:
        case Opcode::DefLGreater:
        case Opcode::DefLGreaterEqual:
        case Opcode::DefLLess:
        case Opcode::DefLLessEqual:
        case Opcode::DefMid:
        case Opcode::DefLNot:
        case Opcode::DefLNotEqual:
        case Opcode::DefLoadTable:
        case Opcode::DefLOr:
        case Opcode::DefMatch:
        case Opcode::DefMod:
        case Opcode::DefMultiply:
        case Opcode::DefNAnd:
        case Opcode::DefNOr:
        case Opcode::DefNot:
        case Opcode::DefObjectType:
        case Opcode::DefOr:
        case Opcode::DefPackage:
        case Opcode::DefVarPackage:
        case Opcode::DefRefOf:
        case Opcode::DefShiftLeft:
        case Opcode::DefShiftRight:
        case Opcode::DefSizeOf:
        case Opcode::DefStore:
        case Opcode::DefSubtract:
        case Opcode::DefTimer:
        case Opcode::DefToBCD:
        case Opcode::DefToBuffer:
        case Opcode::DefToDecimalString:
        case Opcode::DefToHexString:
        case Opcode::DefToInteger:
        case Opcode::DefToString:
        case Opcode::DefWait:
        case Opcode::DefXOr:
//        case Opcode::MethodInvocation:
            return true;
        default:
            return false;
    }
}

std::string_view to_string(Opcode opcode) {
    switch (opcode) {
        case Opcode::DefAlias:
            return "DefAlias";
        case Opcode::DefName:
            return "DefName";
        case Opcode::DefScope:
            return "DefScope";
        case Opcode::DefBankField:
            return "DefBankField";
        case Opcode::DefCreateBitField:
            return "DefCreateBitField";
        case Opcode::DefCreateByteField:
            return "DefCreateByteField";
        case Opcode::DefCreateDWordField:
            return "DefCreateDWordField";
        case Opcode::DefCreateField:
            return "DefCreateField";
        case Opcode::DefCreateQWordField:
            return "DefCreateQWordField";
        case Opcode::DefCreateWordField:
            return "DefCreateWordField";
        case Opcode::DefDataRegion:
            return "DefDataRegion";
        case Opcode::DefExternal:
            return "DefExternal";
        case Opcode::DefOpRegion:
            return "DefOpRegion";
        case Opcode::DefPowerRes:
            return "DefPowerRes";
        case Opcode::DefThermalZone:
            return "DefThermalZone";
        case Opcode::DefAcquire:
            return "DefAcquire";
        case Opcode::DefAdd:
            return "DefAdd";
        case Opcode::DefAnd:
            return "DefAnd";
        case Opcode::DefBuffer:
            return "DefBuffer";
        case Opcode::DefConcat:
            return "DefConcat";
        case Opcode::DefConcatRes:
            return "DefConcatRes";
        case Opcode::DefCondRefOf:
            return "DefCondRefOf";
        case Opcode::DefCopyObject:
            return "DefCopyObject";
        case Opcode::DefDecrement:
            return "DefDecrement";
        case Opcode::DefDerefOf:
            return "DefDerefOf";
        case Opcode::DefDivide:
            return "DefDivide";
        case Opcode::DefFindSetLeftBit:
            return "DefFindSetLeftBit";
        case Opcode::DefFindSetRightBit:
            return "DefFindSetRightBit";
        case Opcode::DefFromBCD:
            return "DefFromBCD";
        case Opcode::DefIncrement:
            return "DefIncrement";
        case Opcode::DefIndex:
            return "DefIndex";
        case Opcode::DefLAnd:
            return "DefLAnd";
        case Opcode::DefLEqual:
            return "DefLEqual";
        case Opcode::DefLGreater:
            return "DefLGreater";
        case Opcode::DefLGreaterEqual:
            return "DefLGreaterEqual";
        case Opcode::DefLLess:
            return "DefLLess";
        case Opcode::DefLLessEqual:
            return "DefLLessEqual";
        case Opcode::DefMid:
            return "DefMid";
        case Opcode::DefLNot:
            return "DefLNot";
        case Opcode::DefLNotEqual:
            return "DefLNotEqual";
        case Opcode::DefLoadTable:
            return "DefLoadTable";
        case Opcode::DefLOr:
            return "DefLOr";
        case Opcode::DefMatch:
            return "DefMatch";
        case Opcode::DefMod:
            return "DefMod";
        case Opcode::DefMultiply:
            return "DefMultiply";
        case Opcode::DefNAnd:
            return "DefNAnd";
        case Opcode::DefNOr:
            return "DefNOr";
        case Opcode::DefNot:
            return "DefNot";
        case Opcode::DefObjectType:
            return "DefObjectType";
        case Opcode::DefOr:
            return "DefOr";
        case Opcode::DefPackage:
            return "DefPackage";
        case Opcode::DefVarPackage:
            return "DefVarPackage";
        case Opcode::DefRefOf:
            return "DefRefOf";
        case Opcode::DefShiftLeft:
            return "DefShiftLeft";
        case Opcode::DefShiftRight:
            return "DefShiftRight";
        case Opcode::DefSizeOf:
            return "DefSizeOf";
        case Opcode::DefStore:
            return "DefStore";
        case Opcode::DefSubtract:
            return "DefSubtract";
        case Opcode::DefTimer:
            return "DefTimer";
        case Opcode::DefToBCD:
            return "DefToBCD";
        case Opcode::DefToBuffer:
            return "DefToBuffer";
        case Opcode::DefToDecimalString:
            return "DefToDecimalString";
        case Opcode::DefToHexString:
            return "DefToHexString";
        case Opcode::DefToInteger:
            return "DefToInteger";
        case Opcode::DefToString:
            return "DefToString";
        case Opcode::DefWait:
            return "DefWait";
        case Opcode::DefXOr:
            return "DefXOr";
        case Opcode::DefMethod:
            return "DefMethod";
        case Opcode::DefBreak:
            return "DefBreak";
        case Opcode::DefBreakPoint:
            return "DefBreakPoint";
        case Opcode::DefContinue:
            return "DefContinue";
        case Opcode::DefFatal:
            return "DefFatal";
        case Opcode::DefIfElse:
            return "DefIfElse";
        case Opcode::DefNoop:
            return "DefNoop";
        case Opcode::DefNotify:
            return "DefNotify";
        case Opcode::DefRelease:
            return "DefRelease";
        case Opcode::DefReset:
            return "DefReset";
        case Opcode::DefReturn:
            return "DefReturn";
        case Opcode::DefSignal:
            return "DefSignal";
        case Opcode::DefSleep:
            return "DefSleep";
        case Opcode::DefStall:
            return "DefStall";
        case Opcode::DefWhile:
            return "DefWhile";
        case Opcode::RevisionOp:
            return "RevisionOp";
        case Opcode::DefDevice:
            return "DefDevice";
        default:
            return "Invalid";
    }
}

bool is_digit_char(uint8_t value) {
    return value >= 0x30 && value <= 0x39;
}

bool is_name_char(uint8_t value) {
    return is_digit_char(value) || is_lead_name_char(value);
}

bool is_root_char(uint8_t value) {
    return value == '\\';
}

bool is_data_ref_object(Opcode opcode) {
    return is_data_object(opcode) || is_object_reference(opcode);
}

bool is_object_reference(Opcode opcode) {
    return false;
}

bool is_data_object(Opcode opcode) {
    return is_computational_data(opcode) || opcode == Opcode::DefPackage || opcode == Opcode::DefVarPackage;
}

bool is_const_obj(Opcode opcode) {
    switch (opcode) {
        case Opcode::ZeroOp:
        case Opcode::OneOp:
        case Opcode::OnesOp:
            return true;
        default:
            return false;
    }
}

bool is_computational_data(Opcode opcode) {
    if(is_const_obj(opcode))
        return true;

    switch (opcode) {
        case Opcode::ByteConst:
        case Opcode::WordConst:
        case Opcode::DWordConst:
        case Opcode::QWordConst:
        case Opcode::String:
        case Opcode::RevisionOp:
        case Opcode::DefBuffer:
            return true;
        default:
            return false;
    }
}

size_t opcode_length(Opcode opcode) {
    auto value = static_cast<uint16_t>(opcode);
    return value > 0xff ? 2 : 1;
}

bool has_prefix_path(uint8_t value) {
    return value == '^';
}

bool is_null_name(uint8_t value) {
    return value == 0x00;
}

bool is_multi_name_path(uint8_t value) {
    return value == 0x2f; // MultiNamePrefix
}

bool is_dual_name_path(uint8_t value) {
    return value == 0x2e; // DualNamePrefix
}

bool is_lead_name_char(uint8_t value) {
    return (value >= 0x41 && value <= 0x5A) || value == '_';
}

bool is_arg_obj(Opcode opcode) {
    switch (opcode) {
        case Opcode::Arg0Op:
        case Opcode::Arg1Op:
        case Opcode::Arg2Op:
        case Opcode::Arg3Op:
        case Opcode::Arg4Op:
        case Opcode::Arg5Op:
        case Opcode::Arg6Op:
            return true;
        default:
            return false;
    }
}

bool is_local_object(Opcode opcode) {
    switch (opcode) {
        case Opcode::Local0Op:
        case Opcode::Local1Op:
        case Opcode::Local2Op:
        case Opcode::Local3Op:
        case Opcode::Local4Op:
        case Opcode::Local5Op:
        case Opcode::Local6Op:
        case Opcode::Local7Op:
            return true;
        default:
            return false;
    }
};

bool is_term_arg(Opcode opcode) {
    return is_data_object(opcode) || is_expression_opcode(opcode) || is_arg_obj(opcode) || is_local_object(opcode);
}

//bool is_package_element(Opcode opcode) {
//    return is_name
//}
