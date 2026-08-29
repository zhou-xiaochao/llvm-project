#include "CPU0TargetMachine.h"
#include "TargetInfo/CPU0TargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeCPU0Target() {
  RegisterTargetMachine<CPU0TargetMachine> X(getTheCPU0Target());
}

static Reloc::Model
getEffectiveRelocModel(std::optional<Reloc::Model> RM) {
  return RM.value_or(Reloc::Static);
}

static std::string computeDataLayout() {
  return "e-m:e-p:32:32-i64:64-n32-S32";
}

CPU0TargetMachine::CPU0TargetMachine(
    const Target &T, const Triple &TT, StringRef CPU, StringRef FS,
    const TargetOptions &Options, std::optional<Reloc::Model> RM,
    std::optional<CodeModel::Model> CM, CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, computeDataLayout(), TT, CPU, FS, Options,
          getEffectiveRelocModel(RM),
          getEffectiveCodeModel(CM, CodeModel::Small), OL) {}