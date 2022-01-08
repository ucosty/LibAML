DefinitionBlock ("test.aml", "DSDT", 2, "", "", 0x0) {
    Name (_ADR, 0x00020000)
    
    Method(_S1D, 0, NotSerialized) {
        Return (0x00)
    }

    Method(_S2D, 0, NotSerialized) {
        Return (0xcafebabe)
    }
}
