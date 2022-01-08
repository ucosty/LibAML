## Opcodes

| Value               | Name               |
|---------------------|--------------------|
| 0x00                | ZeroOp             |
| 0x01                | OneOp              |
| 0x06                | DefAlias            |
| 0x08                | NameOp             |
| 0x0A                | BytePrefix         |
| 0x0B                | WordPrefix         |
| 0x0C                | DWordPrefix        |
| 0x0D                | StringPrefix       |
| 0x0E                | QWordPrefix        |
| 0x10                | ScopeOp            |
| 0x11                | BufferOp           |
| 0x12                | PackageOp          |
| 0x13                | VarPackageOp       |
| 0x14                | MethodOp           |
| 0x2E (.)            | DualNamePrefix     |
| 0x2F (/)            | MultiNamePrefix    |
| 0x30-0x39 ('0'-'9') | DigitChar          |
| 0x41-0x5A (‘A’-‘Z’) | NameChar           |
| 0x5B ([)            | ExtOpPrefix        |
| 0x5B 0x01           | MutexOp            |
| 0x5B 0x02           | EventOp            |
| 0x5B 0x12           | CondRefOfOp        |
| 0x5B 0x13           | CreateFieldOp      |
| 0x5B 0x1F           | LoadTableOp        |
| 0x5B 0x20           | LoadOp             |
| 0x5B 0x21           | StallOp            |
| 0x5B 0x22           | SleepOp            |
| 0x5B 0x23           | AcquireOp          |
| 0x5B 0x24           | SignalOp           |
| 0x5B 0x25           | WaitOp             |
| 0x5B 0x26           | ResetOp            |
| 0x5B 0x27           | ReleaseOp          |
| 0x5B 0x28           | FromBCDOp          |
| 0x5B 0x29           | ToBCD              |
| 0x5B 0x2A           | UnloadOp           |
| 0x5B 0x30           | RevisionOp         |
| 0x5B 0x31           | DebugOp            |
| 0x5B 0x32           | FatalOp            |
| 0x5B 0x33           | TimerOp            |
| 0x5B 0x80           | OpRegionOp         |
| 0x5B 0x81           | FieldOp            |
| 0x5B 0x82           | DeviceOpList       |
| 0x5B 0x83           | ProcessorOp        |
| 0x5B 0x84           | PowerResOp         |
| 0x5B 0x85           | ThermalZoneOpList  |
| 0x5B 0x86           | IndexFieldOp       |
| 0x5B 0x87           | BankFieldOp        |
| 0x5B 0x88           | DataRegionOp       |
| 0x5C (‘\’)          | RootChar           |
| 0x5E (‘^’)          | ParentPrefixChar   |
| 0x5F(‘_’)           | NameChar           |
| 0x60 (‘`’)          | Local0Op           |
| 0x61 (‘a’)          | Local1Op           |
| 0x62 (‘b’)          | Local2Op           |
| 0x63 (‘c’)          | Local3Op           |
| 0x64 (‘d’)          | Local4Op           |
| 0x65 (‘e’)          | Local5Op           |
| 0x66 (‘f’)          | Local6Op           |
| 0x67 (‘g’)          | Local7Op           |
| 0x68 (‘h’)          | Arg0Op             |
| 0x69 (‘i’)          | Arg1Op             |
| 0x6A (‘j’)          | Arg2Op             |
| 0x6B (‘k’)          | Arg3Op             |
| 0x6C (‘l’)          | Arg4Op             |
| 0x6D (‘m’)          | Arg5Op             |
| 0x6E (‘n’)          | Arg6Op             |
| 0x70                | StoreOp            |
| 0x71                | RefOfOp            |
| 0x72                | AddOp              |
| 0x73                | ConcatOp           |
| 0x74                | SubtractOp         |
| 0x75                | IncrementOp        |
| 0x76                | DecrementOp        |
| 0x77                | MultiplyOp         |
| 0x78                | DivideOp           |
| 0x79                | ShiftLeftOp        |
| 0x7A                | ShiftRightOp       |
| 0x7B                | AndOp              |
| 0x7C                | NandOp             |
| 0x7D                | OrOp               |
| 0x7E                | NorOp              |
| 0x7F                | XorOp              |
| 0x80                | NotOp              |
| 0x81                | FindSetLeftBitOp   |
| 0x82                | FindSetRightBitOp  |
| 0x83                | DerefOfOp          |
| 0x84                | ConcatResOp        |
| 0x85                | ModOp              |
| 0x86                | NotifyOp           |
| 0x87                | SizeOfOp           |
| 0x88                | IndexOp            |
| 0x89                | MatchOp            |
| 0x8A                | CreateDWordFieldOp |
| 0x8B                | CreateWordFieldOp  |
| 0x8C                | CreateByteFieldOp  |
| 0x8D                | CreateBitFieldOp   |
| 0x8E                | TypeOp             |
| 0x8F                | CreateQWordFieldOp |
| 0x90                | LandOp             |
| 0x91                | LorOp              |
| 0x92                | LnotOp             |
| 0x92 0x93           | LNotEqualOp        |
| 0x92 0x94           | LLessEqualOp       |
| 0x92 0x95           | LGreaterEqualOp    |
| 0x93                | LEqualOp           |
| 0x94                | LGreaterOp         |
| 0x95                | LLessOp            |
| 0x96                | ToBufferOp         |
| 0x97                | ToDecimalStringOp  |
| 0x98                | ToHexStringOp      |
| 0x99                | ToIntegerOp        |
| 0x9C                | ToStringOp         |
| 0x9D                | CopyObjectOp       |
| 0x9E                | MidOp              |
| 0x9F                | ContinueOp         |
| 0xA0                | IfOp               |
| 0xA1                | ElseOp             |
| 0xA2                | WhileOp            |
| 0xA3                | NoopOp             |
| 0xA4                | ReturnOp           |
| 0xA5                | BreakOp            |
| 0xCC                | BreakPointOp       |
| 0xFF                | OnesOp             |