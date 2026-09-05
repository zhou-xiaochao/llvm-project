#ifndef LLVM_LIB_TARGET_CPU0_CPU0INSTRINFO_H
#define LLVM_LIB_TARGET_CPU0_CPU0INSTRINFO_H

#include "CPU0RegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "CPU0GenInstrInfo.inc"

namespace llvm {

class CPU0Subtarget;

class CPU0InstrInfo : public CPU0GenInstrInfo {
  CPU0RegisterInfo RI;

public:
  explicit CPU0InstrInfo(CPU0Subtarget &STI);

  const CPU0RegisterInfo &getRegisterInfo() const {
    return RI;
  }
};

} // namespace llvm

#endif