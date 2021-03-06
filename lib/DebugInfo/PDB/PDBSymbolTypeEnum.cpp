//===- PDBSymbolTypeEnum.cpp - --------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/DebugInfo/PDB/PDBSymbolTypeEnum.h"

#include "llvm/DebugInfo/PDB/PDBSymDumper.h"
#include "llvm/DebugInfo/PDB/PDBSymbolTypeBuiltin.h"

#include <utility>

using namespace llvm;
using namespace llvm::pdb;

PDBSymbolTypeEnum::PDBSymbolTypeEnum(const IPDBSession &PDBSession,
                                     std::unique_ptr<IPDBRawSymbol> Symbol)
    : PDBSymbol(PDBSession, std::move(Symbol)) {
  assert(RawSymbol->getSymTag() == PDB_SymType::Enum);
}

void PDBSymbolTypeEnum::dump(PDBSymDumper &Dumper) const { Dumper.dump(*this); }
