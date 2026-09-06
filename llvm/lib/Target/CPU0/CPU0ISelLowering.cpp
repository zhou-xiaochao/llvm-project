//===-- CPU0ISelLowering.cpp - CPU0 DAG Lowering Implementation ----------===//

#include "CPU0ISelLowering.h"

#include "CPU0RegisterInfo.h"
#include "CPU0Subtarget.h"
#include "MCTargetDesc/CPU0MCTargetDesc.h"

#include "llvm/CodeGen/ValueTypes.h"

using namespace llvm;

#define DEBUG_TYPE "cpu0-lower"

CPU0TargetLowering::CPU0TargetLowering(const TargetMachine &TM,
                                       const CPU0Subtarget &STI)
    : TargetLowering(TM), Subtarget(&STI) {

  // CPU0 v0.1 has one native scalar integer register type: i32.
  addRegisterClass(MVT::i32, &CPU0::GPR32RegClass);

  // Derive target register properties after declaring legal register classes.
  computeRegisterProperties(STI.getRegisterInfo());

  // CPU0 uses SP as the architectural stack pointer.
  setStackPointerRegisterToSaveRestore(CPU0::SP);

  // CPU0 v0.1 materialized boolean values are represented as 0 or 1.
  setBooleanContents(ZeroOrOneBooleanContent);

  // Operations directly supported by the current CPU0 instruction subset.
  setOperationAction(ISD::ADD, MVT::i32, Legal);
  setOperationAction(ISD::SUB, MVT::i32, Legal);
  setOperationAction(ISD::AND, MVT::i32, Legal);
  setOperationAction(ISD::OR,  MVT::i32, Legal);
  setOperationAction(ISD::XOR, MVT::i32, Legal);

  // Operations for which CPU0 v0.1 currently has no native instruction.
  setOperationAction(ISD::MUL,  MVT::i32, Expand);
  setOperationAction(ISD::SDIV, MVT::i32, Expand);
  setOperationAction(ISD::UDIV, MVT::i32, Expand);
  setOperationAction(ISD::SREM, MVT::i32, Expand);
  setOperationAction(ISD::UREM, MVT::i32, Expand);

  setOperationAction(ISD::SHL, MVT::i32, Expand);
  setOperationAction(ISD::SRA, MVT::i32, Expand);
  setOperationAction(ISD::SRL, MVT::i32, Expand);
  setOperationAction(ISD::ROTL, MVT::i32, Expand);
  setOperationAction(ISD::ROTR, MVT::i32, Expand);
}