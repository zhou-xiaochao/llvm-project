add_llvm_component_library(LLVMCPU0Info
  CPU0TargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  CPU0
)