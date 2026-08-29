# CPU0 ABI v0.1

## Integer Arguments

arg0 -> A0
arg1 -> A1
arg2+ -> stack

## Return Values

i32 -> V0

## Stack

- stack grows downward
- SP is R13
- FP is R12
- 4-byte basic alignment

## Register Preservation

### Caller-saved

A0
A1
V0
T0
T1
T2

### Callee-saved

S0
S1
FP
RA