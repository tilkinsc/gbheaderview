# gbheaderview
A single-source program which pretty-prints a gameboy/gameboy color header

Example:
```
C:\programming\gbheader>test "Pokemon Yellow.gb"
rst00h - ff 00 00 00 00 00 00 00
rst08h - ff 00 00 00 00 00 00 00
rst10h - ff 00 00 00 00 00 00 00
rst18h - ff 00 00 00 00 00 00 00
rst20h - ff 00 00 00 00 00 00 00
rst28h - ff 00 00 00 00 00 00 00
rst30h - ff 00 00 00 00 00 00 00
rst38h - ff 00 00 00 00 00 00 00

int40h - c3 e5 1d 00 00 00 00 00
int48h - c3 ac 15 00 00 00 00 00
int50h - c3 6a 21 00 00 00 00 00
int58h - c3 79 1f 00 00 00 00 00
int60h - d9 af e0 0f f0 ff 47 cb
int68h - 87 e0 ff f0 44 fe 91 20
int70h - fa f0 40 e6 7f e0 40 78
int78h - e0 ff c9 f0 40 cb ff e0
int80h - 40 c9 af 21 00 c3 06 a0
int88h - 22 05 20 fc c9 3e a0 21
int90h - 00 c3 11 04 00 06 28 77
int98h - 19 05 20 fb c9 ea 22 d1
intA0h - f0 b8 f5 fa 22 d1 cd 7e
intA8h - 3e cd b1 00 f1 cd 7e 3e
intB0h - c9 78 a7 28 0c 79 a7 28
intB8h - 01 04 cd c1 00 05 20 fa
intC0h - c9 2a 12 13 0d 20 fa c9
intC8h - f0 40 cb 7f c2 fe 15 e5
intD0h - 62 6b d1 78 f5 cb 31 3e
intD8h - 0f a1 47 3e f0 a1 4f f1
intE0h - c3 9d 00 f0 40 cb 7f c2
intE8h - 36 16 d5 54 5d 78 f5 26
intF0h - 00 69 29 29 29 44 4d f1
intF8h - e1 c3 d4 15 00 00 00 00

Entry Point - 00 c3 ab 01

Title - POKEMON YELLOW\0

CGB Flag - 80 (CGB and GB)
New Licensee Code - (ASCII) 01 (Nintendo)
SGB Flag - 03 (SGB Functions)

Cartridge Type - 1b (MBC5+RAM+BATTERY)
Rom Size - 05 (1MByte (64 banks) - only 63 banks used by MBC1)
Ram Size - 03 (32 KByte (4 banks * 8 KByte))

Destination Code - 01 (Non-Japanese)
Old Licensee Code - 33 (GBC - See Above)
ROM Version - 00

Header Checksum - 97
Global Checksum - 04 7c
```
