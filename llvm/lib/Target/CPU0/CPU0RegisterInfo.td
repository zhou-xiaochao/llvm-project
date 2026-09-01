//===-- CPU0RegisterInfo.td - CPU0 Register defs -------*- tablegen -*-===//
//
// Register definitions for the CPU0 target.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the CPU0 register file
//===----------------------------------------------------------------------===//

class CPU0Reg<bits<4> num, string n, list<string> alt = []> : Register<n> {
  field bits<4> Num = num;
  let Namespace = "CPU0";
  let HWEncoding{3-0} = num;
  let AltNames = alt;
  let DwarfNumbers = [num];
}

//===----------------------------------------------------------------------===//
//  Registers
//===----------------------------------------------------------------------===//

def ZERO : CPU0Reg<0,  "r0", ["zero"]>;
def AT   : CPU0Reg<1,  "r1", ["at"]>;
def V0   : CPU0Reg<2,  "r2", ["v0"]>;
def V1   : CPU0Reg<3,  "r3", ["v1"]>;
def A0   : CPU0Reg<4,  "r4", ["a0"]>;
def A1   : CPU0Reg<5,  "r5", ["a1"]>;
def T0   : CPU0Reg<6,  "r6", ["t0"]>;
def T1   : CPU0Reg<7,  "r7", ["t1"]>;
def T2   : CPU0Reg<8,  "r8", ["t2"]>;
def S0   : CPU0Reg<9,  "r9", ["s0"]>;
def S1   : CPU0Reg<10, "r10", ["s1"]>;
def GP   : CPU0Reg<11, "r11", ["gp"]>;
def FP   : CPU0Reg<12, "r12", ["fp"]>;
def SP   : CPU0Reg<13, "r13", ["sp"]>;
def RA   : CPU0Reg<14, "r14", ["ra"]>;
def SW   : CPU0Reg<15, "r15", ["sw"]>;

//===----------------------------------------------------------------------===//
//  Register Classes
//===----------------------------------------------------------------------===//

def GPR32 : RegisterClass<"CPU0", [i32], 32,
  (add 
    // Volatile / Caller-saved registers (优先分配，无需保存)
    T2, T1, T0, A1, A0, V1, V0,
    // Callee-saved registers (需要函数序言/尾声保存)
    S1, S0,
    // Frame pointer, sometimes allocable
    FP
  )>;