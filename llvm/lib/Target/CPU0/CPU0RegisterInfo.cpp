#include "CPU0RegisterInfo.h"
#include "CPU0FrameLowering.h"

#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "CPU0GenRegisterInfo.inc"

CPU0RegisterInfo::CPU0RegisterInfo()
    : CPU0GenRegisterInfo(CPU0::RA) {}

BitVector
CPU0RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());

  Reserved.set(CPU0::ZERO);
  Reserved.set(CPU0::AT);
  Reserved.set(CPU0::GP);
  Reserved.set(CPU0::SP);
  Reserved.set(CPU0::RA);
  Reserved.set(CPU0::STATUS);

  return Reserved;
}

const MCPhysReg *
CPU0RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  static const MCPhysReg CalleeSavedRegs[] = {
      CPU0::S0,
      CPU0::S1,
      0
  };

  return CalleeSavedRegs;
}

const TargetRegisterClass *
CPU0RegisterInfo::getPointerRegClass(const MachineFunction &MF,
                                     unsigned Kind) const {
  return &CPU0::GPR32RegClass;
}

bool CPU0RegisterInfo::eliminateFrameIndex(
    MachineBasicBlock::iterator II, int SPAdj,
    unsigned FIOperandNum, RegScavenger *RS) const {
  llvm_unreachable(
      "CPU0 frame index elimination is not implemented yet");
}

Register
CPU0RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return CPU0::SP;
}