//===-- CPU0ISelLowering.h - CPU0 DAG Lowering Interface -------*- C++ -*-===//

#ifndef LLVM_LIB_TARGET_CPU0_CPU0ISELLOWERING_H
#define LLVM_LIB_TARGET_CPU0_CPU0ISELLOWERING_H

#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class CPU0Subtarget;

class CPU0TargetLowering : public TargetLowering {
  const CPU0Subtarget *Subtarget;

public:
  explicit CPU0TargetLowering(const TargetMachine &TM,
                              const CPU0Subtarget &STI);
};

} // namespace llvm

#endif