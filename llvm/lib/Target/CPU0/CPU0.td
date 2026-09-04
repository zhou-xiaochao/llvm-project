//===-- CPU0.td - CPU0 Target Definition ------------------*- tablegen -*-===//
include "llvm/Target/Target.td"
include "CPU0RegisterInfo.td"
include "CPU0InstrFormats.td"
include "CPU0InstrInfo.td"
def CPU0InstrInfo : InstrInfo;
def CPU0 : Target {
    let InstructionSet = CPU0InstrInfo;
}