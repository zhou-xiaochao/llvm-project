#include "CPU0MCTargetDesc.h"

#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/Compiler.h"

using namespace llvm;

//===----------------------------------------------------------------------===//
// TableGen-generated MC instruction descriptions
//===----------------------------------------------------------------------===//

#define GET_INSTRINFO_MC_DESC
#include "CPU0GenInstrInfo.inc"

//===----------------------------------------------------------------------===//
// TableGen-generated MC subtarget descriptions
//===----------------------------------------------------------------------===//

#define GET_SUBTARGETINFO_MC_DESC
#include "CPU0GenSubtargetInfo.inc"

//===----------------------------------------------------------------------===//
// TableGen-generated MC register descriptions
//===----------------------------------------------------------------------===//

#define GET_REGINFO_MC_DESC
#include "CPU0GenRegisterInfo.inc"

//===----------------------------------------------------------------------===//
// Target MC initialization
//===----------------------------------------------------------------------===//

extern "C" LLVM_EXTERNAL_VISIBILITY 
void LLVMInitializeCPU0TargetMC() {
  // CPU0 MC layer will be implemented in a later milestone.
}