#include "TargetInfo/CPU0TargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheCPU0Target() {
    static Target TheCPU0Target;
    return TheCPU0Target;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeCPU0TargetInfo() {
    RegisterTarget<Triple::cpu0> X(getTheCPU0Target(), "cpu0", "CPU0 32-bit [experimental]", "CPU0");
}