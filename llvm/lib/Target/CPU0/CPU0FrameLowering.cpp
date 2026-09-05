#include "CPU0FrameLowering.h"
#include "CPU0Subtarget.h"

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"

using namespace llvm;

CPU0FrameLowering::CPU0FrameLowering(const CPU0Subtarget &STI)
    : TargetFrameLowering(
          TargetFrameLowering::StackGrowsDown,
          Align(4),
          0,
          Align(4)) {}

bool
CPU0FrameLowering::hasFPImpl(const MachineFunction &MF) const {
  // Dedicated frame-pointer handling will be implemented
  // in the stack-frame milestone.
  return false;
}

void CPU0FrameLowering::emitPrologue(
    MachineFunction &MF,
    MachineBasicBlock &MBB) const {
  assert(MF.getFrameInfo().getStackSize() == 0 &&
         "CPU0 stack prologue is not implemented yet");
}

void CPU0FrameLowering::emitEpilogue(
    MachineFunction &MF,
    MachineBasicBlock &MBB) const {
  assert(MF.getFrameInfo().getStackSize() == 0 &&
         "CPU0 stack epilogue is not implemented yet");
}