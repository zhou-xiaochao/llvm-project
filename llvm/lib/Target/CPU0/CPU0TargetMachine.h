#ifndef LLVM_LIB_TARGET_CPU0_CPU0TARGETMACHINE_H
#define LLVM_LIB_TARGET_CPU0_CPU0TARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "CPU0Subtarget.h"
#include <optional>

namespace llvm {

class CPU0TargetMachine : public CodeGenTargetMachineImpl {
  CPU0Subtarget Subtarget;
public:
  CPU0TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    std::optional<Reloc::Model> RM,
                    std::optional<CodeModel::Model> CM,
                    CodeGenOptLevel OL, bool JIT);
  const CPU0Subtarget *
  getSubtargetImpl(const Function &F) const override {
    return &Subtarget;
  }
};

} // namespace llvm

#endif