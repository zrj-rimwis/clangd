//== BodyFarm.h - Factory for conjuring up fake bodies -------------*- C++ -*-//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// BodyFarm is a factory for creating faux implementations for functions/methods
// for analysis purposes.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_ANALYSIS_BODYFARM_H
#define LLVM_CLANG_LIB_ANALYSIS_BODYFARM_H

#include "clang/AST/DeclBase.h"
#include "clang/Basic/LLVM.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/Optional.h"

namespace clang {

class ASTContext;
class FunctionDecl;
#ifdef CLANG_ENABLE_OBJC // __DragonFly__ // assume not needed
class ObjCMethodDecl;
class ObjCPropertyDecl;
#endif
class Stmt;
class CodeInjector;
  
class BodyFarm {
public:
  BodyFarm(ASTContext &C, CodeInjector *injector) : C(C), Injector(injector) {}
  
  /// Factory method for creating bodies for ordinary functions.
  Stmt *getBody(const FunctionDecl *D);

  /// Factory method for creating bodies for Objective-C properties.
#ifdef CLANG_ENABLE_OBJC // __DragonFly__ // assume not needed
  Stmt *getBody(const ObjCMethodDecl *D);
#endif

private:
  typedef llvm::DenseMap<const Decl *, Optional<Stmt *> > BodyMap;

  ASTContext &C;
  BodyMap Bodies;
  CodeInjector *Injector;
};
}

#endif
