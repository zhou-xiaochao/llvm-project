//===-- CPU0InstrInfo.td - CPU0 Instruction Definitions ---*- tablegen -*-===//
//
// CPU0 instruction definitions.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// ALU instructions
//===----------------------------------------------------------------------===//

class ALUrr<string mnemonic, SDNode op>
    : CPU0Inst<
        (outs GPR32:$dst),
        (ins GPR32:$lhs, GPR32:$rhs),
        !strconcat(mnemonic, " $dst, $lhs, $rhs"),
        [(set GPR32:$dst,
              (op GPR32:$lhs, GPR32:$rhs))]
      > {
  let mayLoad = 0;
  let mayStore = 0;
  let hasSideEffects = 0;
}

def ADD : ALUrr<"add", add>;
def SUB : ALUrr<"sub", sub>;
def AND : ALUrr<"and", and>;
def OR  : ALUrr<"or",  or>;
def XOR : ALUrr<"xor", xor>;

//===----------------------------------------------------------------------===//
// Immediate instructions
//===----------------------------------------------------------------------===//

def ADDI : CPU0Inst<
    (outs GPR32:$dst),
    (ins GPR32:$src, i32imm:$imm),
    "addi $dst, $src, $imm"
> {
  let mayLoad = 0;
  let mayStore = 0;
  let hasSideEffects = 0;
}

//===----------------------------------------------------------------------===//
// Memory instructions
//===----------------------------------------------------------------------===//

let mayLoad = 1, mayStore = 0, hasSideEffects = 0 in
def LW : CPU0Inst<
    (outs GPR32:$dst),
    (ins GPR32:$base, i32imm:$offset),
    "lw $dst, $offset($base)"
>;

let mayLoad = 0, mayStore = 1, hasSideEffects = 0 in
def SW : CPU0Inst<
    (outs),
    (ins GPR32:$src, GPR32:$base, i32imm:$offset),
    "sw $src, $offset($base)"
>;