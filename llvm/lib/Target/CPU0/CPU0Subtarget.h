#ifndef LLVM_LIB_TARGET_CPU0_CPU0SUBTARGET_H
#define LLVM_LIB_TARGET_CPU0_CPU0SUBTARGET_H

#include "CPU0FrameLowering.h"
#include "CPU0InstrInfo.h"
#include "CPU0ISelLowering.h"

#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "CPU0GenSubtargetInfo.inc"

namespace llvm {

class CPU0Subtarget : public CPU0GenSubtargetInfo {
  CPU0InstrInfo InstrInfo;
  CPU0TargetLowering TLInfo;  //TargetLowering的初始化必须要在InstrInfo之后因为TargetLowering依赖InstrInfo
  CPU0FrameLowering FrameLowering;

public:
  CPU0Subtarget(const Triple &TT, StringRef CPU, StringRef FS,
                const TargetMachine &TM);

  CPU0Subtarget &
  initializeSubtargetDependencies(StringRef CPU, StringRef FS);

  void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU,
                              StringRef FS);

  const CPU0InstrInfo *getInstrInfo() const override {
    return &InstrInfo;
  }

  const CPU0RegisterInfo *getRegisterInfo() const override {
    return &InstrInfo.getRegisterInfo();
  }

  const CPU0TargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }

  const TargetFrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }
};

} // namespace llvm

#endif