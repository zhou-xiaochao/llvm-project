# CPU0 v0.1 Known Limitations

Not supported:

- floating point
- vector types
- varargs
- tail calls
- PIC
- GOT
- TLS
- exception handling
- dynamic alloca
- object emission
- assembler parser
- disassembler

The initial milestone focuses on:

LLVM IR
-> SelectionDAG
-> MachineInstr
-> MCInst
-> CPU0 assembly