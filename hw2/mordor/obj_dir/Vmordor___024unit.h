// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmordor.h for the primary calling header

#ifndef _VMORDOR___024UNIT_H_
#define _VMORDOR___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vmordor__Syms;

//----------

VL_MODULE(Vmordor___024unit) {
  public:
    
    // LOCAL VARIABLES
    static CData/*2:0*/ __Venumtab_enum_next0[8];
    
    // INTERNAL VARIABLES
  private:
    Vmordor__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmordor___024unit);  ///< Copying not allowed
  public:
    Vmordor___024unit(const char* name = "TOP");
    ~Vmordor___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vmordor__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
