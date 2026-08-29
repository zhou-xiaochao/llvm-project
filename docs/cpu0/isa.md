# CPU0 ISA v0.1

## Overview

- 32-bit architecture
- little endian
- integer-only backend
- fixed 32-bit instructions

## Registers

| Register | ABI Name | Usage |
|---|---|---|
| R0 | ZERO | constant zero |
| R2 | V0 | return value |
| R4 | A0 | argument 0 |
| R5 | A1 | argument 1 |
| R12 | FP | frame pointer |
| R13 | SP | stack pointer |
| R14 | RA | return address |

## Instruction Formats

### A-Type

opcode | ra | rb | rc | shamt

### L-Type

opcode | ra | rb | imm16

### J-Type

opcode | addr24

## Initial Instructions

ADD
SUB
ADDI
AND
OR
XOR
LW
SW
JMP
BEQ
BNE
CALL
RET