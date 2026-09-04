add_llvm_component_group(CPU0)

set(LLVM_TARGET_DEFINITIONS CPU0.td)

tablegen(LLVM CPU0GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM CPU0GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM CPU0GenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(CPU0CommonTableGen)

add_llvm_target(CPU0CodeGen
  CPU0TargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  CPU0Info
  MC
  Support
  Target
  TargetParser

  ADD_TO_COMPONENT
  CPU0
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)