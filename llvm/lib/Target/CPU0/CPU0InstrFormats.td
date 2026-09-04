//===-- CPU0InstrFormats.td - CPU0 Instruction Formats ----*- tablegen -*-===//
//
// Base instruction formats for the CPU0 target.
//
//===---------------------------------------------------------------------===//

class CPU0Inst<dag outs, dag ins, string asmstr,
               list<dag> pattern = []> : Instruction {
  let Namespace = "CPU0";

  let OutOperandList = outs;
  let InOperandList = ins;

  let AsmString = asmstr;
  let Pattern = pattern;

  let Size = 4;
}