// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmordor.h for the primary calling header

#include "Vmordor___024unit.h"
#include "Vmordor__Syms.h"

//==========
CData/*2:0*/ Vmordor___024unit::__Venumtab_enum_next0[8];

VL_CTOR_IMP(Vmordor___024unit) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vmordor___024unit::__Vconfigure(Vmordor__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmordor___024unit::~Vmordor___024unit() {
}

void Vmordor___024unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vmordor___024unit::_ctor_var_reset\n"); );
    // Body
    { int __Vi=0; for (; __Vi<8; ++__Vi) {
            __Venumtab_enum_next0[__Vi] = 0U;
    }}
    __Venumtab_enum_next0[0] = 1U;
    __Venumtab_enum_next0[1] = 2U;
    __Venumtab_enum_next0[2] = 3U;
    __Venumtab_enum_next0[3] = 4U;
    __Venumtab_enum_next0[4] = 0U;
}
