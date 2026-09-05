#include "CPU0InstrInfo.h"
#include "CPU0Subtarget.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "CPU0GenInstrInfo.inc"

CPU0InstrInfo::CPU0InstrInfo(CPU0Subtarget &STI)
    : CPU0GenInstrInfo(), RI() {}