#include "CPU0Subtarget.h"

#include "llvm/Support/Debug.h"

using namespace llvm;

#define DEBUG_TYPE "cpu0-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "CPU0GenSubtargetInfo.inc"

CPU0Subtarget &
CPU0Subtarget::initializeSubtargetDependencies(StringRef CPU,
                                                StringRef FS) {
  StringRef CPUName = CPU;

  if (CPUName.empty())
    CPUName = "generic";

  ParseSubtargetFeatures(CPUName, CPUName, FS);

  return *this;
}

CPU0Subtarget::CPU0Subtarget(
    const Triple &TT, StringRef CPU, StringRef FS,
    const TargetMachine &TM)
    : CPU0GenSubtargetInfo(TT, CPU, CPU, FS),
      InstrInfo(initializeSubtargetDependencies(CPU, FS)),
      TLInfo(TM, *this),
      FrameLowering(*this) {}