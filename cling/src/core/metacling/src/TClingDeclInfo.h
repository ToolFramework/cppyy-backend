/// \file TClingDeclInfo.h
///
/// \brief The file contains a base class of TCling*Info classes.
///
/// \author Vassil Vassilev <vvasilev@cern.ch>
///
/// \date March, 2019
///
/*************************************************************************
 * Copyright (C) 1995-2019, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TClingDeclInfo
#define ROOT_TClingDeclInfo

#include <string>


namespace clang {
   class Decl;
}

namespace CppyyLegacy {

class TClingDeclInfo {
protected:
   const clang::Decl* fDecl = nullptr;
   std::string fNameCache;
public:
   TClingDeclInfo(const clang::Decl* D) : fDecl(D) {}
   virtual ~TClingDeclInfo();

   virtual const clang::Decl* GetDecl() const { return fDecl; }
   clang::Decl* GetDecl() {
      return const_cast<clang::Decl*>(const_cast<const TClingDeclInfo*>(this)->GetDecl());
   }
   virtual bool IsValid() const { return GetDecl(); }
   virtual const char* Name();
};

} // namespace CppyyLegacy

#endif // ROOT_TClingDeclInfo
