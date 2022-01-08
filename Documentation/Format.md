# Format

### Root Block
~~~
AMLCode := DefinitionBlockHeader TermList
~~~

### Definition Block

~~~
DefinitionBlockHeader := TableSignature : 4
                         TableLength : 4
                         ComplianceRevision : 1
                         CheckSum : 1
                         OemID : 6
                         OemTableID : 8
                         OemRevision : 4
                         CreatorID : 4
                         CreatorRevision : 4
~~~

| Field              | Size    | Description                                                               |
|--------------------|---------|---------------------------------------------------------------------------|
| TableSignature     | 4 Bytes | Signature of the AML file (could be DSDT or SSDT)                         |
| TableLength        | 4 Bytes | Size of the AML file including header                                     |
| ComplianceRevision | 1 Byte  | Value = 1 for 32-bit arithmetic, Value >= 2 for 64-bit arithmetic         |
| CheckSum           | 1 Byte  | Checksum byte                                                             |
| OemID              | 6 Bytes | ID of the original equipment manufacturer (OEM) developing the ACPI table |
| OemTableID         | 8 Bytes | A specific identifier for the table (8-character string)                  |  
| OemRevision        | 4 Bytes | Revision number set by the OEM (32-bit number)                            |
| CreatorID          | 4 Bytes |                                                                           |
| CreatorRevision    | 4 Bytes |                                                                           |

### Term List
~~~
TermList := Nothing | <TermObj TermList>
~~~

### Term Object
~~~
TermObj := Object | StatementOpcode | ExpressionOpcode
~~~

### Object
~~~
Object := NameSpaceModifierObj | NamedObj
~~~

### Term Argument
~~~
TermArg := ExpressionOpcode | DataObject | ArgObj | LocalObj
~~~

### Method Invocation
~~~
MethodInvocation := NameString TermArgList
~~~

### Term Argument List
~~~
TermArgList := Nothing | <termarg termarglist>
~~~

### Statement Opcode
~~~
StatementOpcode := DefBreak | DefBreakPoint | DefContinue | DefFatal | DefIfElse | DefNoop | DefNotify | DefRelease | DefReset | DefReturn | DefSignal | DefSleep | DefStall | DefWhile
~~~

### Expression Opcode
~~~
ExpressionOpcode := DefAcquire | DefAdd | DefAnd | DefBuffer | DefConcat | DefConcatRes | DefCondRefOf | DefCopyObject | DefDecrement | DefDerefOf | DefDivide | DefFindSetLeftBit | DefFindSetRightBit | DefFromBCD | DefIncrement | DefIndex | DefLAnd | DefLEqual | DefLGreater | DefLGreaterEqual | DefLLess | DefLLessEqual | DefMid | DefLNot | DefLNotEqual | DefLoadTable | DefLOr | DefMatch | DefMod | DefMultiply | DefNAnd | DefNOr | DefNot | DefObjectType | DefOr | DefPackage | DefVarPackage | DefRefOf | DefShiftLeft | DefShiftRight | DefSizeOf | DefStore | DefSubtract | DefTimer | DefToBCD | DefToBuffer | DefToDecimalString | DefToHexString | DefToInteger | DefToString | DefWait | DefXOr | MethodInvocation
~~~