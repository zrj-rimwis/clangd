//===- EHPersonalities.h - Compute EH-related information -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_ANALYSIS_EHPERSONALITIES_H
#define LLVM_ANALYSIS_EHPERSONALITIES_H

#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/TinyPtrVector.h"
#include "llvm/Support/ErrorHandling.h"

namespace llvm {
class BasicBlock;
class Function;
class Value;

enum class EHPersonality {
  Unknown,
  GNU_Ada,
  GNU_C,
  GNU_C_SjLj,
  GNU_CXX,
  GNU_CXX_SjLj,
  GNU_ObjC,
#ifdef LLVM_ENABLE_NONELF_TARGETS // __DragonFly__
#ifdef LLVM_ENABLE_MSEH // __DragonFly__
  MSVC_X86SEH,
  MSVC_Win64SEH,
  MSVC_CXX,
  CoreCLR,
#else
  MSVC_X86SEH_disabled,
  MSVC_Win64SEH_disabled,
  MSVC_CXX_disabled,
  CoreCLR_disabled,
#endif
#endif
  Rust
};

/// \brief See if the given exception handling personality function is one
/// that we understand.  If so, return a description of it; otherwise return
/// Unknown.
EHPersonality classifyEHPersonality(const Value *Pers);

/// \brief Returns true if this personality function catches asynchronous
/// exceptions.
#ifdef LLVM_ENABLE_MSEH // __DragonFly__ // assume false
inline bool isAsynchronousEHPersonality(EHPersonality Pers) {
  // The two SEH personality functions can catch asynch exceptions. We assume
  // unknown personalities don't catch asynch exceptions.
  switch (Pers) {
  case EHPersonality::MSVC_X86SEH:
  case EHPersonality::MSVC_Win64SEH:
    return true;
  default:
    return false;
  }
  llvm_unreachable("invalid enum");
}
#endif

/// \brief Returns true if this is a personality function that invokes
/// handler funclets (which must return to it).
#ifdef LLVM_ENABLE_MSEH // __DragonFly__ // assume false
inline bool isFuncletEHPersonality(EHPersonality Pers) {
  switch (Pers) {
  case EHPersonality::MSVC_CXX:
  case EHPersonality::MSVC_X86SEH:
  case EHPersonality::MSVC_Win64SEH:
  case EHPersonality::CoreCLR:
    return true;
  default:
    return false;
  }
  llvm_unreachable("invalid enum");
}
#endif

/// \brief Return true if this personality may be safely removed if there
/// are no invoke instructions remaining in the current function.
inline bool isNoOpWithoutInvoke(EHPersonality Pers) {
  switch (Pers) {
  case EHPersonality::Unknown:
    return false;
  // All known personalities currently have this behavior
  default:
    return true;
  }
  llvm_unreachable("invalid enum");
}

#ifdef LLVM_ENABLE_MSEH // __DragonFly__ // short circuit to true
bool canSimplifyInvokeNoUnwind(const Function *F);
#endif

#ifdef LLVM_ENABLE_MSEH // __DragonFly__
typedef TinyPtrVector<BasicBlock *> ColorVector;
#endif

/// \brief If an EH funclet personality is in use (see isFuncletEHPersonality),
/// this will recompute which blocks are in which funclet. It is possible that
/// some blocks are in multiple funclets. Consider this analysis to be
/// expensive.
#ifdef LLVM_ENABLE_MSEH // __DragonFly__ // and thus it must go away
DenseMap<BasicBlock *, ColorVector> colorEHFunclets(Function &F);
#endif

} // end namespace llvm

#endif
