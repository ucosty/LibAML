Result<Element *> Parser::parse_acquire() {
    // DefAcquire := AcquireOp MutexObject Timeout
    TRY(ensure_opcode(Opcode::DefAcquire));
    auto self = new Acquire(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_add() {
    // DefAdd := AddOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefAdd));
    auto self = new Add(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_and() {
    // DefAnd := AndOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefAnd));
    auto self = new And(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_buffer() {
    // DefBuffer := BufferOp PkgLength BufferSize ByteList
    TRY(ensure_opcode(Opcode::DefBuffer));
    auto self = new Buffer(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_concat() {
    // DefConcat := ConcatOp Data Data Target
    TRY(ensure_opcode(Opcode::DefConcat));
    auto self = new Concat(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_concat_res() {
    // DefConcatRes := ConcatResOp BufData BufData Target
    TRY(ensure_opcode(Opcode::DefConcatRes));
    auto self = new ConcatRes(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_cond_ref_of() {
    // DefCondRefOf := CondRefOfOp SuperName Target
    TRY(ensure_opcode(Opcode::DefCondRefOf));
    auto self = new CondRefOf(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_copy_object() {
    // DefCopyObject := CopyObjectOp TermArg SimpleName
    TRY(ensure_opcode(Opcode::DefCopyObject));
    auto self = new CopyObject(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_decrement() {
    // DefDecrement := DecrementOp SuperName
    TRY(ensure_opcode(Opcode::DefDecrement));
    auto self = new Decrement(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_deref_of() {
    // DefDerefOf := DerefOfOp ObjReference
    TRY(ensure_opcode(Opcode::DefDerefOf));
    auto self = new DerefOf(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_divide() {
    // DefDivide := DivideOp Dividend Divisor Remainder Quotient
    TRY(ensure_opcode(Opcode::DefDivide));
    auto self = new Divide(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_find_set_left_bit() {
    // DefFindSetLeftBit := FindSetLeftBitOp Operand Target
    TRY(ensure_opcode(Opcode::DefFindSetLeftBit));
    auto self = new FindSetLeftBit(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_find_set_right_bit() {
    // DefFindSetRightBit := FindSetRightBitOp Operand Target
    TRY(ensure_opcode(Opcode::DefFindSetRightBit));
    auto self = new FindSetRightBit(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_from_bcd() {
    // DefFromBcd := FromBcdOp BCDValue Target
    TRY(ensure_opcode(Opcode::DefFromBcd));
    auto self = new FromBcd(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_increment() {
    // DefIncrement := IncrementOp SuperName
    TRY(ensure_opcode(Opcode::DefIncrement));
    auto self = new Increment(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_index() {
    // DefIndex := IndexOp BuffPkgStrObj IndexValue Target
    TRY(ensure_opcode(Opcode::DefIndex));
    auto self = new Index(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_and() {
    // DefLAnd := LandOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLAnd));
    auto self = new LAnd(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_equal() {
    // DefLEqual := LequalOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLEqual));
    auto self = new LEqual(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_greater() {
    // DefLGreater := LgreaterOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLGreater));
    auto self = new LGreater(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_greater_equal() {
    // DefLGreaterEqual := LgreaterEqualOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLGreaterEqual));
    auto self = new LGreaterEqual(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_less() {
    // DefLLess := LlessOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLLess));
    auto self = new LLess(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_less_equal() {
    // DefLLessEqual := LlessEqualOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLLessEqual));
    auto self = new LLessEqual(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_not() {
    // DefLNot := LnotOp Operand
    TRY(ensure_opcode(Opcode::DefLNot));
    auto self = new LNot(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_not_equal() {
    // DefLNotEqual := LnotEqualOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLNotEqual));
    auto self = new LNotEqual(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_load() {
    // DefLoad := LoadOp NameString Target
    TRY(ensure_opcode(Opcode::DefLoad));
    auto self = new Load(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_load_table() {
    // DefLoadTable := LoadTableOp TermArg TermArg TermArg TermArg TermArg TermArg
    TRY(ensure_opcode(Opcode::DefLoadTable));
    auto self = new LoadTable(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_l_or() {
    // DefLOr := LorOp Operand Operand
    TRY(ensure_opcode(Opcode::DefLOr));
    auto self = new LOr(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_match() {
    // DefMatch := MatchOp SearchPkg MatchOpcode Operand MatchOpcode Operand StartIndex
    TRY(ensure_opcode(Opcode::DefMatch));
    auto self = new Match(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_mid() {
    // DefMid := MidOp MidObj TermArg TermArg Target
    TRY(ensure_opcode(Opcode::DefMid));
    auto self = new Mid(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_mod() {
    // DefMod := ModOp Dividend Divisor Target
    TRY(ensure_opcode(Opcode::DefMod));
    auto self = new Mod(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_multiply() {
    // DefMultiply := MultiplyOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefMultiply));
    auto self = new Multiply(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_n_and() {
    // DefNAnd := NandOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefNAnd));
    auto self = new NAnd(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_n_or() {
    // DefNOr := NorOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefNOr));
    auto self = new NOr(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_not() {
    // DefNot := NotOp Operand Target
    TRY(ensure_opcode(Opcode::DefNot));
    auto self = new Not(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_object_type() {
    // DefObjectType := ObjectTypeOp <SimpleName | DebugObj | DefRefOf | DefDerefOf | DefIndex>
    TRY(ensure_opcode(Opcode::DefObjectType));
    auto self = new ObjectType(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_or() {
    // DefOr := OrOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefOr));
    auto self = new Or(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_package() {
    // DefPackage := PackageOp PkgLength NumElements PackageElementList
    TRY(ensure_opcode(Opcode::DefPackage));
    auto self = new Package(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_var_package() {
    // DefVarPackage := VarPackageOp PkgLength VarNumElements PackageElementList
    TRY(ensure_opcode(Opcode::DefVarPackage));
    auto self = new VarPackage(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_ref_of() {
    // DefRefOf := RefOfOp SuperName
    TRY(ensure_opcode(Opcode::DefRefOf));
    auto self = new RefOf(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_shift_left() {
    // DefShiftLeft := ShiftLeftOp Operand ShiftCount Target
    TRY(ensure_opcode(Opcode::DefShiftLeft));
    auto self = new ShiftLeft(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_shift_right() {
    // DefShiftRight := ShiftRightOp Operand ShiftCount Target
    TRY(ensure_opcode(Opcode::DefShiftRight));
    auto self = new ShiftRight(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_size_of() {
    // DefSizeOf := SizeOfOp SuperName
    TRY(ensure_opcode(Opcode::DefSizeOf));
    auto self = new SizeOf(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_store() {
    // DefStore := StoreOp TermArg SuperName
    TRY(ensure_opcode(Opcode::DefStore));
    auto self = new Store(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_subtract() {
    // DefSubtract := SubtractOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefSubtract));
    auto self = new Subtract(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_timer() {
    // DefTimer := TimerOp
    TRY(ensure_opcode(Opcode::DefTimer));
    auto self = new Timer(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_to_bcd() {
    // DefToBcd := ToBcdOp Operand Target
    TRY(ensure_opcode(Opcode::DefToBcd));
    auto self = new ToBcd(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_to_buffer() {
    // DefToBuffer := ToBufferOp Operand Target
    TRY(ensure_opcode(Opcode::DefToBuffer));
    auto self = new ToBuffer(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_to_decimal_string() {
    // DefToDecimalString := ToDecimalStringOp Operand Target
    TRY(ensure_opcode(Opcode::DefToDecimalString));
    auto self = new ToDecimalString(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_to_hex_string() {
    // DefToHexString := ToHexStringOp Operand Target
    TRY(ensure_opcode(Opcode::DefToHexString));
    auto self = new ToHexString(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_to_integer() {
    // DefToInteger := ToIntegerOp Operand Target
    TRY(ensure_opcode(Opcode::DefToInteger));
    auto self = new ToInteger(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_to_string() {
    // DefToString := ToStringOp TermArg LengthArg Target
    TRY(ensure_opcode(Opcode::DefToString));
    auto self = new ToString(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_wait() {
    // DefWait := WaitOp EventObject Operand
    TRY(ensure_opcode(Opcode::DefWait));
    auto self = new Wait(full_size, payload_size);
    return self;
}

Result<Element *> Parser::parse_xor() {
    // DefXor := XorOp Operand Operand Target
    TRY(ensure_opcode(Opcode::DefXor));
    auto self = new Xor(full_size, payload_size);
    return self;
}

