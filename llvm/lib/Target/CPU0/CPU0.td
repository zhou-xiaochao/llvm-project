//===-- CPU0.td - CPU0 Target Definition ------------------*- tablegen -*-===//
include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Subtarget
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features>
    : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

//===----------------------------------------------------------------------===//
// Registers
//===----------------------------------------------------------------------===//

include "CPU0RegisterInfo.td"

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

include "CPU0InstrFormats.td"
include "CPU0InstrInfo.td"

def CPU0InstrInfo : InstrInfo;

def CPU0 : Target {
    let InstructionSet = CPU0InstrInfo;
}