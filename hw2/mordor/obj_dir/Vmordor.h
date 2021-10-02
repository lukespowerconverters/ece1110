// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMORDOR_H_
#define _VMORDOR_H_  // guard

#include "verilated_heavy.h"

//==========

class Vmordor__Syms;
class Vmordor___024unit;


//----------

VL_MODULE(Vmordor) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vmordor___024unit* __PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset_n,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ mordor__DOT__upc;
    CData/*5:0*/ mordor__DOT__data_path__DOT__reg_addr;
    CData/*0:0*/ mordor__DOT__data_path__DOT__regread;
    CData/*0:0*/ mordor__DOT__data_path__DOT__memread;
    CData/*7:0*/ mordor__DOT__control_section__DOT__upc_next;
    CData/*7:0*/ mordor__DOT__control_section__DOT__upc_decode;
    CData/*1:0*/ mordor__DOT__control_section__DOT__upc_sel;
    CData/*2:0*/ mordor__DOT__memory__DOT__mem_counter;
    IData/*31:0*/ mordor__DOT__ir;
    IData/*31:0*/ mordor__DOT__mem_addr;
    IData/*31:0*/ mordor__DOT__mem_data_input;
    IData/*31:0*/ mordor__DOT__data_path__DOT__alu;
    IData/*31:0*/ mordor__DOT__data_path__DOT__reg_a;
    IData/*31:0*/ mordor__DOT__data_path__DOT__reg_b;
    IData/*31:0*/ mordor__DOT__data_path__DOT__exception_target;
    IData/*31:0*/ mordor__DOT__data_path__DOT__bus;
    IData/*31:0*/ mordor__DOT__data_path__DOT__immediate;
    QData/*39:0*/ mordor__DOT__ucode;
    IData/*31:0*/ mordor__DOT__data_path__DOT__regfile[64];
    IData/*31:0*/ mordor__DOT__memory__DOT__mem[256];
    QData/*39:0*/ mordor__DOT__code__DOT__mem[256];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    IData/*31:0*/ mordor__DOT____Vcellout__memory__data_output;
    CData/*4:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clock;
    static CData/*1:0*/ __Vtable1_mordor__DOT__control_section__DOT__upc_sel[32];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmordor__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmordor);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmordor(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmordor();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmordor__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmordor__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmordor__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vmordor__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmordor__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vmordor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmordor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _final_TOP(Vmordor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vmordor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vmordor__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vmordor__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
