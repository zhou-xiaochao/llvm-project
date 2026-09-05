//===-- CPU0MCTargetDesc.h - CPU0 Target Descriptions ----------*- C++ -*-===//

#ifndef LLVM_LIB_TARGET_CPU0_MCTARGETDESC_CPU0MCTARGETDESC_H
#define LLVM_LIB_TARGET_CPU0_MCTARGETDESC_CPU0MCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

namespace llvm {

class Target;
class MCInstrInfo;
class MCRegisterInfo;
class MCSubtargetInfo;

} // namespace llvm

// Defines symbolic names for CPU0 registers.
//
// For example:
//   CPU0::ZERO
//   CPU0::A0
//   CPU0::SP
//   CPU0::RA
//   CPU0::GPR32RegClassID
#define GET_REGINFO_ENUM
#include "CPU0GenRegisterInfo.inc"

// Defines symbolic names for CPU0 instructions.
//
// For example:
//   CPU0::ADD
//   CPU0::SUB
//   CPU0::LW
//   CPU0::SW
#define GET_INSTRINFO_ENUM
#include "CPU0GenInstrInfo.inc"

// Defines CPU0 subtarget enums.
#define GET_SUBTARGETINFO_ENUM
#include "CPU0GenSubtargetInfo.inc"

#endif