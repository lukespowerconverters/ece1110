// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VMORDOR__SYMS_H_
#define _VMORDOR__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vmordor.h"
#include "Vmordor___024unit.h"

// SYMS CLASS
class Vmordor__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmordor*                       TOPp;
    Vmordor___024unit              TOP____024unit;
    
    // CREATORS
    Vmordor__Syms(Vmordor* topp, const char* namep);
    ~Vmordor__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
