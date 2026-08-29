add_llvm_component_library(LLVMCPU0Desc
  CPU0MCTargetDesc.cpp

  LINK_COMPONENTS
  CPU0Info
  MC
  Support

  ADD_TO_COMPONENT
  CPU0
)