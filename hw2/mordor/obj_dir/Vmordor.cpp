// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmordor.h for the primary calling header

#include "Vmordor.h"
#include "Vmordor__Syms.h"

//==========
CData/*1:0*/ Vmordor::__Vtable1_mordor__DOT__control_section__DOT__upc_sel[32];

VL_CTOR_IMP(Vmordor) {
    Vmordor__Syms* __restrict vlSymsp = __VlSymsp = new Vmordor__Syms(this, name());
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT____024unit, Vmordor___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmordor::__Vconfigure(Vmordor__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmordor::~Vmordor() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vmordor::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmordor::eval\n"); );
    Vmordor__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mordor.sv", 11, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmordor::_eval_initial_loop(Vmordor__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mordor.sv", 11, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmordor::_final_TOP(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_final_TOP\n"); );
    // Variables
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF(" 0: %x,  1: %x,  2: %x,  3: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [1U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [2U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [3U]);
    VL_WRITEF(" 4: %x,  5: %x,  6: %x,  7: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [4U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [5U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [6U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [7U]);
    VL_WRITEF(" 8: %x,  9: %x, 10: %x, 11: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [8U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [9U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0xaU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0xbU]);
    VL_WRITEF("12: %x, 13: %x, 14: %x, 15: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0xcU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0xdU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0xeU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0xfU]);
    VL_WRITEF("16: %x, 17: %x, 18: %x, 19: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x10U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x11U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x12U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x13U]);
    VL_WRITEF("20: %x, 21: %x, 22: %x, 23: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x14U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x15U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x16U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x17U]);
    VL_WRITEF("24: %x, 25: %x, 26: %x, 27: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x18U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x19U],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x1aU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x1bU]);
    VL_WRITEF("28: %x, 29: %x, 30: %x, 31: %x\n",32,
              vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x1cU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x1dU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x1eU],32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x1fU]);
    VL_WRITEF(" 0: %x,  1: %x,  2: %x,  3: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [1U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [2U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [3U]);
    VL_WRITEF(" 4: %x,  5: %x,  6: %x,  7: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [4U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [5U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [6U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [7U]);
    VL_WRITEF(" 8: %x,  9: %x, 10: %x, 11: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [8U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [9U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0xaU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0xbU]);
    VL_WRITEF("12: %x, 13: %x, 14: %x, 15: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0xcU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0xdU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0xeU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0xfU]);
    VL_WRITEF("16: %x, 17: %x, 18: %x, 19: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x10U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x11U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x12U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x13U]);
    VL_WRITEF("20: %x, 21: %x, 22: %x, 23: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x14U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x15U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x16U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x17U]);
    VL_WRITEF("24: %x, 25: %x, 26: %x, 27: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x18U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x19U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x1aU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x1bU]);
    VL_WRITEF("28: %x, 29: %x, 30: %x, 31: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x1cU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x1dU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x1eU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x1fU]);
    VL_WRITEF("32: %x, 33: %x, 34: %x, 35: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x20U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x21U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x22U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x23U]);
    VL_WRITEF("36: %x, 37: %x, 38: %x, 39: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x24U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x25U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x26U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x27U]);
    VL_WRITEF("40: %x, 41: %x, 42: %x, 43: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x28U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x29U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x2aU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x2bU]);
    VL_WRITEF("44: %x, 45: %x, 46: %x, 47: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x2cU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x2dU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x2eU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x2fU]);
    VL_WRITEF("48: %x, 49: %x, 50: %x, 51: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x30U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x31U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x32U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x33U]);
    VL_WRITEF("52: %x, 53: %x, 54: %x, 55: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x34U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x35U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x36U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x37U]);
    VL_WRITEF("56: %x, 57: %x, 58: %x, 59: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x38U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x39U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x3aU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x3bU]);
    VL_WRITEF("60: %x, 61: %x, 62: %x, 63: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x3cU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x3dU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x3eU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x3fU]);
    VL_WRITEF("64: %x, 65: %x, 66: %x, 67: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x40U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x41U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x42U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x43U]);
    VL_WRITEF("68: %x, 69: %x, 70: %x, 71: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x44U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x45U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x46U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x47U]);
    VL_WRITEF("72: %x, 73: %x, 74: %x, 75: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x48U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x49U],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x4aU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x4bU]);
    VL_WRITEF("76: %x, 77: %x, 78: %x, 79: %x\n",32,
              vlTOPp->mordor__DOT__memory__DOT__mem
              [0x4cU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x4dU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x4eU],32,vlTOPp->mordor__DOT__memory__DOT__mem
              [0x4fU]);
}

void Vmordor::_initial__TOP__1(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_initial__TOP__1\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    WData/*95:0*/ __Vtemp2[3];
    // Body
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x636f6465U;
    __Vtemp1[2U] = 0x75U;
    VL_READMEM_N(true, 40, 256, 0, VL_CVT_PACK_STR_NW(3, __Vtemp1)
                 , vlTOPp->mordor__DOT__code__DOT__mem
                 , 0, ~VL_ULL(0));
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x6772616dU;
    __Vtemp2[2U] = 0x70726fU;
    VL_READMEM_N(true, 32, 256, 0, VL_CVT_PACK_STR_NW(3, __Vtemp2)
                 , vlTOPp->mordor__DOT__memory__DOT__mem
                 , 0, ~VL_ULL(0));
}

VL_INLINE_OPT void Vmordor::_sequent__TOP__2(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_sequent__TOP__2\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vdlyvdim0__mordor__DOT__data_path__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__data_path__DOT__regfile__v0;
    CData/*7:0*/ __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__memory__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__memory__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v2;
    CData/*4:0*/ __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__mordor__DOT__memory__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__memory__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v3;
    CData/*4:0*/ __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v3;
    SData/*15:0*/ __Vdlyvval__mordor__DOT__memory__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__memory__DOT__mem__v3;
    CData/*7:0*/ __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v4;
    CData/*4:0*/ __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v4;
    CData/*7:0*/ __Vdlyvval__mordor__DOT__memory__DOT__mem__v4;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__memory__DOT__mem__v4;
    CData/*7:0*/ __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v5;
    CData/*4:0*/ __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v5;
    SData/*15:0*/ __Vdlyvval__mordor__DOT__memory__DOT__mem__v5;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__memory__DOT__mem__v5;
    CData/*7:0*/ __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v6;
    CData/*0:0*/ __Vdlyvset__mordor__DOT__memory__DOT__mem__v6;
    CData/*2:0*/ __Vdly__mordor__DOT__memory__DOT__mem_counter;
    IData/*31:0*/ __Vdlyvval__mordor__DOT__data_path__DOT__regfile__v0;
    IData/*31:0*/ __Vdlyvval__mordor__DOT__memory__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__mordor__DOT__memory__DOT__mem__v1;
    IData/*31:0*/ __Vdlyvval__mordor__DOT__memory__DOT__mem__v6;
    // Body
    __Vdly__mordor__DOT__memory__DOT__mem_counter = vlTOPp->mordor__DOT__memory__DOT__mem_counter;
    __Vdlyvset__mordor__DOT__data_path__DOT__regfile__v0 = 0U;
    VL_WRITEF("uPC=[%x] uword=[%x] UBR=[%x] RegSel=[%1#] InstReg=[%x]\n",
              8,vlTOPp->mordor__DOT__upc,40,vlTOPp->mordor__DOT__ucode,
              3,(7U & (IData)((vlTOPp->mordor__DOT__ucode 
                               >> 0xdU))),3,(7U & (IData)(
                                                          (vlTOPp->mordor__DOT__ucode 
                                                           >> 0x1bU))),
              32,vlTOPp->mordor__DOT__ir);
    __Vdlyvset__mordor__DOT__memory__DOT__mem__v0 = 0U;
    __Vdlyvset__mordor__DOT__memory__DOT__mem__v1 = 0U;
    __Vdlyvset__mordor__DOT__memory__DOT__mem__v2 = 0U;
    __Vdlyvset__mordor__DOT__memory__DOT__mem__v3 = 0U;
    __Vdlyvset__mordor__DOT__memory__DOT__mem__v4 = 0U;
    __Vdlyvset__mordor__DOT__memory__DOT__mem__v5 = 0U;
    __Vdlyvset__mordor__DOT__memory__DOT__mem__v6 = 0U;
    __Vdly__mordor__DOT__memory__DOT__mem_counter = 
        ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                        >> 0x24U))) ? 1U : (((1U <= (IData)(vlTOPp->mordor__DOT__memory__DOT__mem_counter)) 
                                             & (4U 
                                                > (IData)(vlTOPp->mordor__DOT__memory__DOT__mem_counter)))
                                             ? vlSymsp->TOP____024unit.__Venumtab_enum_next0
                                            [vlTOPp->mordor__DOT__memory__DOT__mem_counter]
                                             : 0U));
    if ((((IData)((vlTOPp->mordor__DOT__ucode >> 0x18U)) 
          & (IData)((vlTOPp->mordor__DOT__ucode >> 0x19U))) 
         & (0U != (IData)(vlTOPp->mordor__DOT__data_path__DOT__reg_addr)))) {
        __Vdlyvval__mordor__DOT__data_path__DOT__regfile__v0 
            = vlTOPp->mordor__DOT__data_path__DOT__bus;
        __Vdlyvset__mordor__DOT__data_path__DOT__regfile__v0 = 1U;
        __Vdlyvdim0__mordor__DOT__data_path__DOT__regfile__v0 
            = vlTOPp->mordor__DOT__data_path__DOT__reg_addr;
    }
    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode >> 0x16U)))) {
        vlTOPp->mordor__DOT__data_path__DOT__reg_b 
            = ((IData)(vlTOPp->reset_n) ? vlTOPp->mordor__DOT__data_path__DOT__bus
                : 0U);
    }
    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode >> 0x17U)))) {
        vlTOPp->mordor__DOT__data_path__DOT__reg_a 
            = ((IData)(vlTOPp->reset_n) ? vlTOPp->mordor__DOT__data_path__DOT__bus
                : 0U);
    }
    if ((4U == (IData)(vlTOPp->mordor__DOT__memory__DOT__mem_counter))) {
        if ((1U & (~ (IData)((vlTOPp->mordor__DOT__ucode 
                              >> 0x25U))))) {
            vlTOPp->mordor__DOT____Vcellout__memory__data_output = 0U;
            if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                               >> 0x23U)))) {
                if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                   >> 0x22U)))) {
                    vlTOPp->mordor__DOT____Vcellout__memory__data_output 
                        = vlTOPp->mordor__DOT__memory__DOT__mem
                        [(0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                   >> 2U))];
                } else {
                    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                       >> 0x21U)))) {
                        vlTOPp->mordor__DOT____Vcellout__memory__data_output 
                            = vlTOPp->mordor__DOT__memory__DOT__mem
                            [(0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                       >> 2U))];
                    } else {
                        vlTOPp->mordor__DOT____Vcellout__memory__data_output 
                            = ((0xffffff00U & vlTOPp->mordor__DOT____Vcellout__memory__data_output) 
                               | (0xffU & (vlTOPp->mordor__DOT__memory__DOT__mem
                                           [(0xffU 
                                             & (vlTOPp->mordor__DOT__mem_addr 
                                                >> 2U))] 
                                           >> (0x1fU 
                                               & ((0x10U 
                                                   & (vlTOPp->mordor__DOT__mem_addr 
                                                      << 3U)) 
                                                  + 
                                                  (8U 
                                                   & (vlTOPp->mordor__DOT__mem_addr 
                                                      << 3U)))))));
                    }
                }
            } else {
                if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                   >> 0x22U)))) {
                    vlTOPp->mordor__DOT____Vcellout__memory__data_output 
                        = ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 0x21U)))
                            ? (((~ ((IData)(0xffffU) 
                                    << (0x10U & (vlTOPp->mordor__DOT__mem_addr 
                                                 << 3U)))) 
                                & vlTOPp->mordor__DOT____Vcellout__memory__data_output) 
                               | ((0xffffU & (vlTOPp->mordor__DOT__memory__DOT__mem
                                              [(0xffU 
                                                & (vlTOPp->mordor__DOT__mem_addr 
                                                   >> 2U))] 
                                              >> (0x10U 
                                                  & (vlTOPp->mordor__DOT__mem_addr 
                                                     << 3U)))) 
                                  << (0x10U & (vlTOPp->mordor__DOT__mem_addr 
                                               << 3U))))
                            : ((0xffffff00U & vlTOPp->mordor__DOT____Vcellout__memory__data_output) 
                               | (0xffU & (vlTOPp->mordor__DOT__memory__DOT__mem
                                           [(0xffU 
                                             & (vlTOPp->mordor__DOT__mem_addr 
                                                >> 2U))] 
                                           >> (0x1fU 
                                               & ((0x10U 
                                                   & (vlTOPp->mordor__DOT__mem_addr 
                                                      << 3U)) 
                                                  + 
                                                  (8U 
                                                   & (vlTOPp->mordor__DOT__mem_addr 
                                                      << 3U))))))));
                } else {
                    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                       >> 0x21U)))) {
                        vlTOPp->mordor__DOT____Vcellout__memory__data_output 
                            = ((0xffff0000U & vlTOPp->mordor__DOT____Vcellout__memory__data_output) 
                               | (0xffffU & (vlTOPp->mordor__DOT__memory__DOT__mem
                                             [(0xffU 
                                               & (vlTOPp->mordor__DOT__mem_addr 
                                                  >> 2U))] 
                                             >> (0x10U 
                                                 & (vlTOPp->mordor__DOT__mem_addr 
                                                    << 3U)))));
                    } else {
                        vlTOPp->mordor__DOT____Vcellout__memory__data_output 
                            = vlTOPp->mordor__DOT__memory__DOT__mem
                            [(0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                       >> 2U))];
                    }
                }
            }
        }
    }
    if ((4U == (IData)(vlTOPp->mordor__DOT__memory__DOT__mem_counter))) {
        if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                           >> 0x25U)))) {
            if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                               >> 0x23U)))) {
                if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                   >> 0x22U)))) {
                    __Vdlyvval__mordor__DOT__memory__DOT__mem__v0 
                        = vlTOPp->mordor__DOT__mem_data_input;
                    __Vdlyvset__mordor__DOT__memory__DOT__mem__v0 = 1U;
                    __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v0 
                        = (0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                    >> 2U));
                } else {
                    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                       >> 0x21U)))) {
                        __Vdlyvval__mordor__DOT__memory__DOT__mem__v1 
                            = vlTOPp->mordor__DOT__mem_data_input;
                        __Vdlyvset__mordor__DOT__memory__DOT__mem__v1 = 1U;
                        __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v1 
                            = (0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                        >> 2U));
                    } else {
                        __Vdlyvval__mordor__DOT__memory__DOT__mem__v2 
                            = (0xffU & vlTOPp->mordor__DOT__mem_data_input);
                        __Vdlyvset__mordor__DOT__memory__DOT__mem__v2 = 1U;
                        __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v2 
                            = (0x1fU & ((0x10U & (vlTOPp->mordor__DOT__mem_addr 
                                                  << 3U)) 
                                        + (8U & (vlTOPp->mordor__DOT__mem_addr 
                                                 << 3U))));
                        __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v2 
                            = (0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                        >> 2U));
                    }
                }
            } else {
                if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                   >> 0x22U)))) {
                    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                       >> 0x21U)))) {
                        __Vdlyvval__mordor__DOT__memory__DOT__mem__v3 
                            = (0xffffU & (vlTOPp->mordor__DOT__mem_data_input 
                                          >> (0x10U 
                                              & (vlTOPp->mordor__DOT__mem_addr 
                                                 << 3U))));
                        __Vdlyvset__mordor__DOT__memory__DOT__mem__v3 = 1U;
                        __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v3 
                            = (0x10U & (vlTOPp->mordor__DOT__mem_addr 
                                        << 3U));
                        __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v3 
                            = (0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                        >> 2U));
                    } else {
                        __Vdlyvval__mordor__DOT__memory__DOT__mem__v4 
                            = (0xffU & vlTOPp->mordor__DOT__mem_data_input);
                        __Vdlyvset__mordor__DOT__memory__DOT__mem__v4 = 1U;
                        __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v4 
                            = (0x1fU & ((0x10U & (vlTOPp->mordor__DOT__mem_addr 
                                                  << 3U)) 
                                        + (8U & (vlTOPp->mordor__DOT__mem_addr 
                                                 << 3U))));
                        __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v4 
                            = (0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                        >> 2U));
                    }
                } else {
                    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode 
                                       >> 0x21U)))) {
                        __Vdlyvval__mordor__DOT__memory__DOT__mem__v5 
                            = (0xffffU & (vlTOPp->mordor__DOT__mem_data_input 
                                          >> (0x10U 
                                              & (vlTOPp->mordor__DOT__mem_addr 
                                                 << 3U))));
                        __Vdlyvset__mordor__DOT__memory__DOT__mem__v5 = 1U;
                        __Vdlyvlsb__mordor__DOT__memory__DOT__mem__v5 
                            = (0x10U & (vlTOPp->mordor__DOT__mem_addr 
                                        << 3U));
                        __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v5 
                            = (0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                        >> 2U));
                    } else {
                        __Vdlyvval__mordor__DOT__memory__DOT__mem__v6 
                            = vlTOPp->mordor__DOT__mem_data_input;
                        __Vdlyvset__mordor__DOT__memory__DOT__mem__v6 = 1U;
                        __Vdlyvdim0__mordor__DOT__memory__DOT__mem__v6 
                            = (0xffU & (vlTOPp->mordor__DOT__mem_addr 
                                        >> 2U));
                    }
                }
            }
        }
    }
    if (__Vdlyvset__mordor__DOT__data_path__DOT__regfile__v0) {
        vlTOPp->mordor__DOT__data_path__DOT__regfile[__Vdlyvdim0__mordor__DOT__data_path__DOT__regfile__v0] 
            = __Vdlyvval__mordor__DOT__data_path__DOT__regfile__v0;
    }
    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode >> 0x1aU)))) {
        vlTOPp->mordor__DOT__ir = ((IData)(vlTOPp->reset_n)
                                    ? vlTOPp->mordor__DOT__data_path__DOT__bus
                                    : 0U);
    }
    vlTOPp->mordor__DOT__upc = ((IData)(vlTOPp->reset_n)
                                 ? (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_next)
                                 : 0U);
    if (__Vdlyvset__mordor__DOT__memory__DOT__mem__v0) {
        vlTOPp->mordor__DOT__memory__DOT__mem[__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v0] 
            = __Vdlyvval__mordor__DOT__memory__DOT__mem__v0;
    }
    if (__Vdlyvset__mordor__DOT__memory__DOT__mem__v1) {
        vlTOPp->mordor__DOT__memory__DOT__mem[__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v1] 
            = __Vdlyvval__mordor__DOT__memory__DOT__mem__v1;
    }
    if (__Vdlyvset__mordor__DOT__memory__DOT__mem__v2) {
        vlTOPp->mordor__DOT__memory__DOT__mem[__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v2))) 
                & vlTOPp->mordor__DOT__memory__DOT__mem
                [__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v2]) 
               | ((IData)(__Vdlyvval__mordor__DOT__memory__DOT__mem__v2) 
                  << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v2)));
    }
    if (__Vdlyvset__mordor__DOT__memory__DOT__mem__v3) {
        vlTOPp->mordor__DOT__memory__DOT__mem[__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v3] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v3))) 
                & vlTOPp->mordor__DOT__memory__DOT__mem
                [__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v3]) 
               | ((IData)(__Vdlyvval__mordor__DOT__memory__DOT__mem__v3) 
                  << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v3)));
    }
    if (__Vdlyvset__mordor__DOT__memory__DOT__mem__v4) {
        vlTOPp->mordor__DOT__memory__DOT__mem[__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v4] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v4))) 
                & vlTOPp->mordor__DOT__memory__DOT__mem
                [__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v4]) 
               | ((IData)(__Vdlyvval__mordor__DOT__memory__DOT__mem__v4) 
                  << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v4)));
    }
    if (__Vdlyvset__mordor__DOT__memory__DOT__mem__v5) {
        vlTOPp->mordor__DOT__memory__DOT__mem[__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v5] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v5))) 
                & vlTOPp->mordor__DOT__memory__DOT__mem
                [__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v5]) 
               | ((IData)(__Vdlyvval__mordor__DOT__memory__DOT__mem__v5) 
                  << (IData)(__Vdlyvlsb__mordor__DOT__memory__DOT__mem__v5)));
    }
    if (__Vdlyvset__mordor__DOT__memory__DOT__mem__v6) {
        vlTOPp->mordor__DOT__memory__DOT__mem[__Vdlyvdim0__mordor__DOT__memory__DOT__mem__v6] 
            = __Vdlyvval__mordor__DOT__memory__DOT__mem__v6;
    }
    vlTOPp->mordor__DOT__memory__DOT__mem_counter = __Vdly__mordor__DOT__memory__DOT__mem_counter;
    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode >> 0x25U)))) {
        vlTOPp->mordor__DOT__mem_data_input = vlTOPp->mordor__DOT__data_path__DOT__bus;
    }
    if ((1U & (IData)((vlTOPp->mordor__DOT__ucode >> 0x24U)))) {
        vlTOPp->mordor__DOT__mem_addr = vlTOPp->mordor__DOT__data_path__DOT__bus;
    }
    if ((0x40U & vlTOPp->mordor__DOT__ir)) {
        if ((0x20U & vlTOPp->mordor__DOT__ir)) {
            if ((0x10U & vlTOPp->mordor__DOT__ir)) {
                if ((8U & vlTOPp->mordor__DOT__ir)) {
                    if (VL_UNLIKELY((4U & vlTOPp->mordor__DOT__ir))) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb9U;
                        VL_FINISH_MT("decode.sv", 96, "");
                    } else {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                    }
                } else {
                    if ((4U & vlTOPp->mordor__DOT__ir)) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                    } else {
                        if (((((((((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU))) 
                                   | (1U == (7U & (vlTOPp->mordor__DOT__ir 
                                                   >> 0xcU)))) 
                                  | (2U == (7U & (vlTOPp->mordor__DOT__ir 
                                                  >> 0xcU)))) 
                                 | (3U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))) 
                                | (4U == (7U & (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))) 
                               | (5U == (7U & (vlTOPp->mordor__DOT__ir 
                                               >> 0xcU)))) 
                              | (6U == (7U & (vlTOPp->mordor__DOT__ir 
                                              >> 0xcU)))) 
                             | (7U == (7U & (vlTOPp->mordor__DOT__ir 
                                             >> 0xcU))))) {
                            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                                = ((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))
                                    ? 0xb6U : ((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x98U
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0xa2U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x9dU
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0xb6U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 0xa7U
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0xcU)))
                                                        ? 0xb1U
                                                        : 0x9dU)))))));
                        }
                    }
                }
            } else {
                vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                    = ((8U & vlTOPp->mordor__DOT__ir)
                        ? ((4U & vlTOPp->mordor__DOT__ir)
                            ? 0x6aU : 0xb6U) : ((4U 
                                                 & vlTOPp->mordor__DOT__ir)
                                                 ? 0x6fU
                                                 : 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->mordor__DOT__ir 
                                                      >> 0xcU)))
                                                  ? 0x78U
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->mordor__DOT__ir 
                                                       >> 0xcU)))
                                                   ? 0x7cU
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x80U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x8aU
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x85U
                                                      : 
                                                     ((7U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 0x8fU
                                                       : 0xb6U))))))));
            }
        } else {
            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                = ((0x10U & vlTOPp->mordor__DOT__ir)
                    ? 0xb6U : ((8U & vlTOPp->mordor__DOT__ir)
                                ? 0xb6U : ((4U & vlTOPp->mordor__DOT__ir)
                                            ? 0xb6U
                                            : 0xbaU)));
        }
    } else {
        if ((0x20U & vlTOPp->mordor__DOT__ir)) {
            if ((0x10U & vlTOPp->mordor__DOT__ir)) {
                if ((8U & vlTOPp->mordor__DOT__ir)) {
                    vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                } else {
                    if ((4U & vlTOPp->mordor__DOT__ir)) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0x30U;
                    } else {
                        if (((((((((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU))) 
                                   | (1U == (7U & (vlTOPp->mordor__DOT__ir 
                                                   >> 0xcU)))) 
                                  | (2U == (7U & (vlTOPp->mordor__DOT__ir 
                                                  >> 0xcU)))) 
                                 | (3U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))) 
                                | (4U == (7U & (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))) 
                               | (5U == (7U & (vlTOPp->mordor__DOT__ir 
                                               >> 0xcU)))) 
                              | (6U == (7U & (vlTOPp->mordor__DOT__ir 
                                              >> 0xcU)))) 
                             | (7U == (7U & (vlTOPp->mordor__DOT__ir 
                                             >> 0xcU))))) {
                            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                                = ((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))
                                    ? ((0U == (0x7fU 
                                               & (vlTOPp->mordor__DOT__ir 
                                                  >> 0x19U)))
                                        ? 0x4cU : 0x4fU)
                                    : ((1U == (7U & 
                                               (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))
                                        ? 0x58U : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x52U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x55U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x67U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (0x7fU 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0x19U)))
                                                        ? 0x5bU
                                                        : 0x5eU)
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0xcU)))
                                                        ? 0x64U
                                                        : 0x61U)))))));
                        }
                    }
                }
            } else {
                vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                    = ((8U & vlTOPp->mordor__DOT__ir)
                        ? 0xb6U : ((4U & vlTOPp->mordor__DOT__ir)
                                    ? 0xb6U : ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x17U
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x21U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0xdU
                                                     : 0xb6U)))));
            }
        } else {
            if ((0x10U & vlTOPp->mordor__DOT__ir)) {
                if ((8U & vlTOPp->mordor__DOT__ir)) {
                    vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                } else {
                    if ((4U & vlTOPp->mordor__DOT__ir)) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0x74U;
                    } else {
                        if (((((((((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU))) 
                                   | (1U == (7U & (vlTOPp->mordor__DOT__ir 
                                                   >> 0xcU)))) 
                                  | (2U == (7U & (vlTOPp->mordor__DOT__ir 
                                                  >> 0xcU)))) 
                                 | (3U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))) 
                                | (4U == (7U & (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))) 
                               | (5U == (7U & (vlTOPp->mordor__DOT__ir 
                                               >> 0xcU)))) 
                              | (6U == (7U & (vlTOPp->mordor__DOT__ir 
                                              >> 0xcU)))) 
                             | (7U == (7U & (vlTOPp->mordor__DOT__ir 
                                             >> 0xcU))))) {
                            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                                = ((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))
                                    ? 0x31U : ((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x3aU
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x34U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x37U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x49U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (0x7fU 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0x19U)))
                                                        ? 0x3dU
                                                        : 0x40U)
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0xcU)))
                                                        ? 0x46U
                                                        : 0x43U)))))));
                        }
                    }
                }
            } else {
                vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                    = ((8U & vlTOPp->mordor__DOT__ir)
                        ? 0xb6U : ((4U & vlTOPp->mordor__DOT__ir)
                                    ? 0xb6U : ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x12U
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x1cU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 8U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x26U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 0x2bU
                                                       : 0xb6U)))))));
            }
        }
    }
}

void Vmordor::_settle__TOP__3(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_settle__TOP__3\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x40U & vlTOPp->mordor__DOT__ir)) {
        if ((0x20U & vlTOPp->mordor__DOT__ir)) {
            if ((0x10U & vlTOPp->mordor__DOT__ir)) {
                if ((8U & vlTOPp->mordor__DOT__ir)) {
                    if (VL_UNLIKELY((4U & vlTOPp->mordor__DOT__ir))) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb9U;
                        VL_FINISH_MT("decode.sv", 96, "");
                    } else {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                    }
                } else {
                    if ((4U & vlTOPp->mordor__DOT__ir)) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                    } else {
                        if (((((((((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU))) 
                                   | (1U == (7U & (vlTOPp->mordor__DOT__ir 
                                                   >> 0xcU)))) 
                                  | (2U == (7U & (vlTOPp->mordor__DOT__ir 
                                                  >> 0xcU)))) 
                                 | (3U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))) 
                                | (4U == (7U & (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))) 
                               | (5U == (7U & (vlTOPp->mordor__DOT__ir 
                                               >> 0xcU)))) 
                              | (6U == (7U & (vlTOPp->mordor__DOT__ir 
                                              >> 0xcU)))) 
                             | (7U == (7U & (vlTOPp->mordor__DOT__ir 
                                             >> 0xcU))))) {
                            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                                = ((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))
                                    ? 0xb6U : ((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x98U
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0xa2U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x9dU
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0xb6U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 0xa7U
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0xcU)))
                                                        ? 0xb1U
                                                        : 0x9dU)))))));
                        }
                    }
                }
            } else {
                vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                    = ((8U & vlTOPp->mordor__DOT__ir)
                        ? ((4U & vlTOPp->mordor__DOT__ir)
                            ? 0x6aU : 0xb6U) : ((4U 
                                                 & vlTOPp->mordor__DOT__ir)
                                                 ? 0x6fU
                                                 : 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->mordor__DOT__ir 
                                                      >> 0xcU)))
                                                  ? 0x78U
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->mordor__DOT__ir 
                                                       >> 0xcU)))
                                                   ? 0x7cU
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x80U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x8aU
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x85U
                                                      : 
                                                     ((7U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 0x8fU
                                                       : 0xb6U))))))));
            }
        } else {
            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                = ((0x10U & vlTOPp->mordor__DOT__ir)
                    ? 0xb6U : ((8U & vlTOPp->mordor__DOT__ir)
                                ? 0xb6U : ((4U & vlTOPp->mordor__DOT__ir)
                                            ? 0xb6U
                                            : 0xbaU)));
        }
    } else {
        if ((0x20U & vlTOPp->mordor__DOT__ir)) {
            if ((0x10U & vlTOPp->mordor__DOT__ir)) {
                if ((8U & vlTOPp->mordor__DOT__ir)) {
                    vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                } else {
                    if ((4U & vlTOPp->mordor__DOT__ir)) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0x30U;
                    } else {
                        if (((((((((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU))) 
                                   | (1U == (7U & (vlTOPp->mordor__DOT__ir 
                                                   >> 0xcU)))) 
                                  | (2U == (7U & (vlTOPp->mordor__DOT__ir 
                                                  >> 0xcU)))) 
                                 | (3U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))) 
                                | (4U == (7U & (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))) 
                               | (5U == (7U & (vlTOPp->mordor__DOT__ir 
                                               >> 0xcU)))) 
                              | (6U == (7U & (vlTOPp->mordor__DOT__ir 
                                              >> 0xcU)))) 
                             | (7U == (7U & (vlTOPp->mordor__DOT__ir 
                                             >> 0xcU))))) {
                            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                                = ((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))
                                    ? ((0U == (0x7fU 
                                               & (vlTOPp->mordor__DOT__ir 
                                                  >> 0x19U)))
                                        ? 0x4cU : 0x4fU)
                                    : ((1U == (7U & 
                                               (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))
                                        ? 0x58U : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x52U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x55U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x67U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (0x7fU 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0x19U)))
                                                        ? 0x5bU
                                                        : 0x5eU)
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0xcU)))
                                                        ? 0x64U
                                                        : 0x61U)))))));
                        }
                    }
                }
            } else {
                vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                    = ((8U & vlTOPp->mordor__DOT__ir)
                        ? 0xb6U : ((4U & vlTOPp->mordor__DOT__ir)
                                    ? 0xb6U : ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x17U
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x21U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0xdU
                                                     : 0xb6U)))));
            }
        } else {
            if ((0x10U & vlTOPp->mordor__DOT__ir)) {
                if ((8U & vlTOPp->mordor__DOT__ir)) {
                    vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0xb6U;
                } else {
                    if ((4U & vlTOPp->mordor__DOT__ir)) {
                        vlTOPp->mordor__DOT__control_section__DOT__upc_decode = 0x74U;
                    } else {
                        if (((((((((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU))) 
                                   | (1U == (7U & (vlTOPp->mordor__DOT__ir 
                                                   >> 0xcU)))) 
                                  | (2U == (7U & (vlTOPp->mordor__DOT__ir 
                                                  >> 0xcU)))) 
                                 | (3U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))) 
                                | (4U == (7U & (vlTOPp->mordor__DOT__ir 
                                                >> 0xcU)))) 
                               | (5U == (7U & (vlTOPp->mordor__DOT__ir 
                                               >> 0xcU)))) 
                              | (6U == (7U & (vlTOPp->mordor__DOT__ir 
                                              >> 0xcU)))) 
                             | (7U == (7U & (vlTOPp->mordor__DOT__ir 
                                             >> 0xcU))))) {
                            vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                                = ((0U == (7U & (vlTOPp->mordor__DOT__ir 
                                                 >> 0xcU)))
                                    ? 0x31U : ((1U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x3aU
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x34U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 0x37U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x49U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (0x7fU 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0x19U)))
                                                        ? 0x3dU
                                                        : 0x40U)
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->mordor__DOT__ir 
                                                            >> 0xcU)))
                                                        ? 0x46U
                                                        : 0x43U)))))));
                        }
                    }
                }
            } else {
                vlTOPp->mordor__DOT__control_section__DOT__upc_decode 
                    = ((8U & vlTOPp->mordor__DOT__ir)
                        ? 0xb6U : ((4U & vlTOPp->mordor__DOT__ir)
                                    ? 0xb6U : ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->mordor__DOT__ir 
                                                    >> 0xcU)))
                                                ? 0x12U
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->mordor__DOT__ir 
                                                        >> 0xcU)))
                                                    ? 0x1cU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 0xcU)))
                                                     ? 8U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->mordor__DOT__ir 
                                                          >> 0xcU)))
                                                      ? 0x26U
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->mordor__DOT__ir 
                                                           >> 0xcU)))
                                                       ? 0x2bU
                                                       : 0xb6U)))))));
            }
        }
    }
    vlTOPp->mordor__DOT__ucode = ((IData)(vlTOPp->reset_n)
                                   ? vlTOPp->mordor__DOT__code__DOT__mem
                                  [vlTOPp->mordor__DOT__upc]
                                   : VL_ULL(0));
    vlTOPp->mordor__DOT__data_path__DOT__regread = 
        (((IData)((vlTOPp->mordor__DOT__ucode >> 0x18U)) 
          & (~ (IData)((vlTOPp->mordor__DOT__ucode 
                        >> 0x19U)))) & (6U >= (7U & (IData)(
                                                            (vlTOPp->mordor__DOT__ucode 
                                                             >> 0x1bU)))));
    vlTOPp->mordor__DOT__data_path__DOT__memread = 
        (1U & ((IData)((vlTOPp->mordor__DOT__ucode 
                        >> 0x14U)) & (~ (IData)((vlTOPp->mordor__DOT__ucode 
                                                 >> 0x25U)))));
    if ((0U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                              >> 0x1bU))))) {
        vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0x20U;
    } else {
        if ((1U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                  >> 0x1bU))))) {
            vlTOPp->mordor__DOT__data_path__DOT__reg_addr 
                = (0x1fU & (vlTOPp->mordor__DOT__ir 
                            >> 7U));
        } else {
            if ((2U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                      >> 0x1bU))))) {
                vlTOPp->mordor__DOT__data_path__DOT__reg_addr 
                    = (0x1fU & (vlTOPp->mordor__DOT__ir 
                                >> 0xfU));
            } else {
                if ((3U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 0x1bU))))) {
                    vlTOPp->mordor__DOT__data_path__DOT__reg_addr 
                        = (0x1fU & (vlTOPp->mordor__DOT__ir 
                                    >> 0x14U));
                } else {
                    if ((7U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 0x1bU))))) {
                        vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0U;
                    } else {
                        if ((5U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                                  >> 0x1bU))))) {
                            vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0U;
                        } else {
                            if ((6U == (7U & (IData)(
                                                     (vlTOPp->mordor__DOT__ucode 
                                                      >> 0x1bU))))) {
                                vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                              >> 0x10U))))) {
        vlTOPp->mordor__DOT__data_path__DOT__immediate 
            = ((((0x80000000U & vlTOPp->mordor__DOT__ir)
                  ? 0xfffffU : 0U) << 0xcU) | (0xfffU 
                                               & (vlTOPp->mordor__DOT__ir 
                                                  >> 0x14U)));
    } else {
        if ((2U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                  >> 0x10U))))) {
            vlTOPp->mordor__DOT__data_path__DOT__immediate 
                = ((((0x80000000U & vlTOPp->mordor__DOT__ir)
                      ? 0xfffffU : 0U) << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->mordor__DOT__ir 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 7U))));
        } else {
            if ((4U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                      >> 0x10U))))) {
                vlTOPp->mordor__DOT__data_path__DOT__immediate 
                    = (0xfffff000U & vlTOPp->mordor__DOT__ir);
            } else {
                if ((5U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 0x10U))))) {
                    vlTOPp->mordor__DOT__data_path__DOT__immediate 
                        = ((0xff000U & vlTOPp->mordor__DOT__ir) 
                           | ((0x800U & (vlTOPp->mordor__DOT__ir 
                                         >> 9U)) | 
                              (0x7feU & (vlTOPp->mordor__DOT__ir 
                                         >> 0x14U))));
                } else {
                    if ((3U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 0x10U))))) {
                        vlTOPp->mordor__DOT__data_path__DOT__immediate 
                            = ((((0x80U & vlTOPp->mordor__DOT__ir)
                                  ? 0xfffffU : 0U) 
                                << 0xcU) | ((0x800U 
                                             & (vlTOPp->mordor__DOT__ir 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlTOPp->mordor__DOT__ir 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlTOPp->mordor__DOT__ir 
                                                     >> 7U)))));
                    }
                }
            }
        }
    }
    if (((((((((0U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                        >> 8U)))) | 
               (1U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                        >> 8U))))) 
              | (2U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                         >> 8U))))) 
             | (3U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                        >> 8U))))) 
            | (4U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                       >> 8U))))) | 
           (5U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                    >> 8U))))) | (6U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->mordor__DOT__ucode 
                                                              >> 8U))))) 
         | (7U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                    >> 8U)))))) {
        vlTOPp->mordor__DOT__data_path__DOT__alu = 
            ((0U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                      >> 8U)))) ? vlTOPp->mordor__DOT__data_path__DOT__reg_a
              : ((1U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 8U))))
                  ? vlTOPp->mordor__DOT__data_path__DOT__reg_b
                  : ((2U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 8U))))
                      ? ((IData)(1U) + vlTOPp->mordor__DOT__data_path__DOT__reg_a)
                      : ((3U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                                  >> 8U))))
                          ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                             - (IData)(1U)) : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(
                                                           (vlTOPp->mordor__DOT__ucode 
                                                            >> 8U))))
                                                ? ((IData)(4U) 
                                                   + vlTOPp->mordor__DOT__data_path__DOT__reg_a)
                                                : (
                                                   (5U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(
                                                               (vlTOPp->mordor__DOT__ucode 
                                                                >> 8U))))
                                                    ? 
                                                   (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                                    - (IData)(4U))
                                                    : 
                                                   ((6U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(
                                                                (vlTOPp->mordor__DOT__ucode 
                                                                 >> 8U))))
                                                     ? 
                                                    (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                                     + vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                                     : 
                                                    (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                                     - vlTOPp->mordor__DOT__data_path__DOT__reg_b))))))));
    } else {
        if (((((((((8U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U)))) 
                   | (9U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 8U))))) 
                  | (0xaU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                               >> 8U))))) 
                 | (0xbU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 8U))))) 
                | (0xcU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                             >> 8U))))) 
               | (0xdU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U))))) 
              | (0xeU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                           >> 8U))))) 
             | (0xfU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 8U)))))) {
            vlTOPp->mordor__DOT__data_path__DOT__alu 
                = ((8U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U))))
                    ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                       << (0x1fU & vlTOPp->mordor__DOT__data_path__DOT__reg_b))
                    : ((9U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                                >> 8U))))
                        ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                           >> (0x1fU & vlTOPp->mordor__DOT__data_path__DOT__reg_b))
                        : ((0xaU == (0x1fU & (IData)(
                                                     (vlTOPp->mordor__DOT__ucode 
                                                      >> 8U))))
                            ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                               >> (0x1fU & vlTOPp->mordor__DOT__data_path__DOT__reg_b))
                            : ((0xbU == (0x1fU & (IData)(
                                                         (vlTOPp->mordor__DOT__ucode 
                                                          >> 8U))))
                                ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                   & vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                : ((0xcU == (0x1fU 
                                             & (IData)(
                                                       (vlTOPp->mordor__DOT__ucode 
                                                        >> 8U))))
                                    ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                       | vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                    : ((0xdU == (0x1fU 
                                                 & (IData)(
                                                           (vlTOPp->mordor__DOT__ucode 
                                                            >> 8U))))
                                        ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                           ^ vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                        : ((0xeU == 
                                            (0x1fU 
                                             & (IData)(
                                                       (vlTOPp->mordor__DOT__ucode 
                                                        >> 8U))))
                                            ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                               < vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                            : (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                               < vlTOPp->mordor__DOT__data_path__DOT__reg_b))))))));
        } else {
            if ((0x10U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U))))) {
                vlTOPp->mordor__DOT__data_path__DOT__alu = 0x200U;
            } else {
                if ((0x11U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                                >> 8U))))) {
                    vlTOPp->mordor__DOT__data_path__DOT__alu 
                        = (0xffffeffeU & vlTOPp->mordor__DOT__data_path__DOT__reg_a);
                } else {
                    if ((0x12U == (0x1fU & (IData)(
                                                   (vlTOPp->mordor__DOT__ucode 
                                                    >> 8U))))) {
                        vlTOPp->mordor__DOT__data_path__DOT__alu 
                            = vlTOPp->mordor__DOT__data_path__DOT__exception_target;
                    }
                }
            }
        }
    }
    VL_WRITEF("A, B, op, ALU = %x %x %2# %x\n",32,vlTOPp->mordor__DOT__data_path__DOT__reg_a,
              32,vlTOPp->mordor__DOT__data_path__DOT__reg_b,
              5,(0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                  >> 8U))),32,vlTOPp->mordor__DOT__data_path__DOT__alu);
    VL_WRITEF("PC = %x\n",32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x20U]);
    vlTOPp->mordor__DOT__data_path__DOT__bus = (((1U 
                                                  & (IData)(
                                                            (vlTOPp->mordor__DOT__ucode 
                                                             >> 0x13U)))
                                                  ? vlTOPp->mordor__DOT__data_path__DOT__immediate
                                                  : 
                                                 ((1U 
                                                   & (IData)(
                                                             (vlTOPp->mordor__DOT__ucode 
                                                              >> 0x15U)))
                                                   ? vlTOPp->mordor__DOT__data_path__DOT__alu
                                                   : 
                                                  ((IData)(vlTOPp->mordor__DOT__data_path__DOT__regread)
                                                    ? 
                                                   vlTOPp->mordor__DOT__data_path__DOT__regfile
                                                   [vlTOPp->mordor__DOT__data_path__DOT__reg_addr]
                                                    : 
                                                   ((IData)(vlTOPp->mordor__DOT__data_path__DOT__memread)
                                                     ? vlTOPp->mordor__DOT____Vcellout__memory__data_output
                                                     : 0U)))) 
                                                & ((1U 
                                                    & (IData)(
                                                              (vlTOPp->mordor__DOT__ucode 
                                                               >> 0x13U)))
                                                    ? 0xffffffffU
                                                    : 
                                                   ((1U 
                                                     & (IData)(
                                                               (vlTOPp->mordor__DOT__ucode 
                                                                >> 0x15U)))
                                                     ? 0xffffffffU
                                                     : 
                                                    ((IData)(vlTOPp->mordor__DOT__data_path__DOT__regread)
                                                      ? 0xffffffffU
                                                      : 
                                                     ((IData)(vlTOPp->mordor__DOT__data_path__DOT__memread)
                                                       ? 0xffffffffU
                                                       : 0U)))));
    vlTOPp->__Vtableidx1 = (((0U == vlTOPp->mordor__DOT__data_path__DOT__alu) 
                             << 4U) | ((((0U == (IData)(vlTOPp->mordor__DOT__memory__DOT__mem_counter))
                                          ? 0U : 1U) 
                                        << 3U) | (7U 
                                                  & (IData)(
                                                            (vlTOPp->mordor__DOT__ucode 
                                                             >> 0xdU)))));
    vlTOPp->mordor__DOT__control_section__DOT__upc_sel 
        = vlTOPp->__Vtable1_mordor__DOT__control_section__DOT__upc_sel
        [vlTOPp->__Vtableidx1];
    vlTOPp->mordor__DOT__control_section__DOT__upc_next 
        = (0xffU & ((2U & (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_sel))
                     ? ((1U & (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_sel))
                         ? (IData)(vlTOPp->mordor__DOT__upc)
                         : ((IData)(1U) + (IData)(vlTOPp->mordor__DOT__upc)))
                     : ((1U & (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_sel))
                         ? (IData)(vlTOPp->mordor__DOT__ucode)
                         : (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_decode))));
}

VL_INLINE_OPT void Vmordor::_combo__TOP__4(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_combo__TOP__4\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mordor__DOT__ucode = ((IData)(vlTOPp->reset_n)
                                   ? vlTOPp->mordor__DOT__code__DOT__mem
                                  [vlTOPp->mordor__DOT__upc]
                                   : VL_ULL(0));
    vlTOPp->mordor__DOT__data_path__DOT__regread = 
        (((IData)((vlTOPp->mordor__DOT__ucode >> 0x18U)) 
          & (~ (IData)((vlTOPp->mordor__DOT__ucode 
                        >> 0x19U)))) & (6U >= (7U & (IData)(
                                                            (vlTOPp->mordor__DOT__ucode 
                                                             >> 0x1bU)))));
    vlTOPp->mordor__DOT__data_path__DOT__memread = 
        (1U & ((IData)((vlTOPp->mordor__DOT__ucode 
                        >> 0x14U)) & (~ (IData)((vlTOPp->mordor__DOT__ucode 
                                                 >> 0x25U)))));
    if ((0U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                              >> 0x1bU))))) {
        vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0x20U;
    } else {
        if ((1U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                  >> 0x1bU))))) {
            vlTOPp->mordor__DOT__data_path__DOT__reg_addr 
                = (0x1fU & (vlTOPp->mordor__DOT__ir 
                            >> 7U));
        } else {
            if ((2U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                      >> 0x1bU))))) {
                vlTOPp->mordor__DOT__data_path__DOT__reg_addr 
                    = (0x1fU & (vlTOPp->mordor__DOT__ir 
                                >> 0xfU));
            } else {
                if ((3U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 0x1bU))))) {
                    vlTOPp->mordor__DOT__data_path__DOT__reg_addr 
                        = (0x1fU & (vlTOPp->mordor__DOT__ir 
                                    >> 0x14U));
                } else {
                    if ((7U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 0x1bU))))) {
                        vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0U;
                    } else {
                        if ((5U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                                  >> 0x1bU))))) {
                            vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0U;
                        } else {
                            if ((6U == (7U & (IData)(
                                                     (vlTOPp->mordor__DOT__ucode 
                                                      >> 0x1bU))))) {
                                vlTOPp->mordor__DOT__data_path__DOT__reg_addr = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((1U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                              >> 0x10U))))) {
        vlTOPp->mordor__DOT__data_path__DOT__immediate 
            = ((((0x80000000U & vlTOPp->mordor__DOT__ir)
                  ? 0xfffffU : 0U) << 0xcU) | (0xfffU 
                                               & (vlTOPp->mordor__DOT__ir 
                                                  >> 0x14U)));
    } else {
        if ((2U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                  >> 0x10U))))) {
            vlTOPp->mordor__DOT__data_path__DOT__immediate 
                = ((((0x80000000U & vlTOPp->mordor__DOT__ir)
                      ? 0xfffffU : 0U) << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->mordor__DOT__ir 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->mordor__DOT__ir 
                                                         >> 7U))));
        } else {
            if ((4U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                      >> 0x10U))))) {
                vlTOPp->mordor__DOT__data_path__DOT__immediate 
                    = (0xfffff000U & vlTOPp->mordor__DOT__ir);
            } else {
                if ((5U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 0x10U))))) {
                    vlTOPp->mordor__DOT__data_path__DOT__immediate 
                        = ((0xff000U & vlTOPp->mordor__DOT__ir) 
                           | ((0x800U & (vlTOPp->mordor__DOT__ir 
                                         >> 9U)) | 
                              (0x7feU & (vlTOPp->mordor__DOT__ir 
                                         >> 0x14U))));
                } else {
                    if ((3U == (7U & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 0x10U))))) {
                        vlTOPp->mordor__DOT__data_path__DOT__immediate 
                            = ((((0x80U & vlTOPp->mordor__DOT__ir)
                                  ? 0xfffffU : 0U) 
                                << 0xcU) | ((0x800U 
                                             & (vlTOPp->mordor__DOT__ir 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlTOPp->mordor__DOT__ir 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlTOPp->mordor__DOT__ir 
                                                     >> 7U)))));
                    }
                }
            }
        }
    }
    if (((((((((0U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                        >> 8U)))) | 
               (1U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                        >> 8U))))) 
              | (2U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                         >> 8U))))) 
             | (3U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                        >> 8U))))) 
            | (4U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                       >> 8U))))) | 
           (5U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                    >> 8U))))) | (6U 
                                                  == 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->mordor__DOT__ucode 
                                                              >> 8U))))) 
         | (7U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                    >> 8U)))))) {
        vlTOPp->mordor__DOT__data_path__DOT__alu = 
            ((0U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                      >> 8U)))) ? vlTOPp->mordor__DOT__data_path__DOT__reg_a
              : ((1U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 8U))))
                  ? vlTOPp->mordor__DOT__data_path__DOT__reg_b
                  : ((2U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 8U))))
                      ? ((IData)(1U) + vlTOPp->mordor__DOT__data_path__DOT__reg_a)
                      : ((3U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                                  >> 8U))))
                          ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                             - (IData)(1U)) : ((4U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(
                                                           (vlTOPp->mordor__DOT__ucode 
                                                            >> 8U))))
                                                ? ((IData)(4U) 
                                                   + vlTOPp->mordor__DOT__data_path__DOT__reg_a)
                                                : (
                                                   (5U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(
                                                               (vlTOPp->mordor__DOT__ucode 
                                                                >> 8U))))
                                                    ? 
                                                   (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                                    - (IData)(4U))
                                                    : 
                                                   ((6U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(
                                                                (vlTOPp->mordor__DOT__ucode 
                                                                 >> 8U))))
                                                     ? 
                                                    (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                                     + vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                                     : 
                                                    (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                                     - vlTOPp->mordor__DOT__data_path__DOT__reg_b))))))));
    } else {
        if (((((((((8U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U)))) 
                   | (9U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 8U))))) 
                  | (0xaU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                               >> 8U))))) 
                 | (0xbU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                              >> 8U))))) 
                | (0xcU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                             >> 8U))))) 
               | (0xdU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U))))) 
              | (0xeU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                           >> 8U))))) 
             | (0xfU == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                          >> 8U)))))) {
            vlTOPp->mordor__DOT__data_path__DOT__alu 
                = ((8U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U))))
                    ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                       << (0x1fU & vlTOPp->mordor__DOT__data_path__DOT__reg_b))
                    : ((9U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                                >> 8U))))
                        ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                           >> (0x1fU & vlTOPp->mordor__DOT__data_path__DOT__reg_b))
                        : ((0xaU == (0x1fU & (IData)(
                                                     (vlTOPp->mordor__DOT__ucode 
                                                      >> 8U))))
                            ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                               >> (0x1fU & vlTOPp->mordor__DOT__data_path__DOT__reg_b))
                            : ((0xbU == (0x1fU & (IData)(
                                                         (vlTOPp->mordor__DOT__ucode 
                                                          >> 8U))))
                                ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                   & vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                : ((0xcU == (0x1fU 
                                             & (IData)(
                                                       (vlTOPp->mordor__DOT__ucode 
                                                        >> 8U))))
                                    ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                       | vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                    : ((0xdU == (0x1fU 
                                                 & (IData)(
                                                           (vlTOPp->mordor__DOT__ucode 
                                                            >> 8U))))
                                        ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                           ^ vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                        : ((0xeU == 
                                            (0x1fU 
                                             & (IData)(
                                                       (vlTOPp->mordor__DOT__ucode 
                                                        >> 8U))))
                                            ? (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                               < vlTOPp->mordor__DOT__data_path__DOT__reg_b)
                                            : (vlTOPp->mordor__DOT__data_path__DOT__reg_a 
                                               < vlTOPp->mordor__DOT__data_path__DOT__reg_b))))))));
        } else {
            if ((0x10U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                            >> 8U))))) {
                vlTOPp->mordor__DOT__data_path__DOT__alu = 0x200U;
            } else {
                if ((0x11U == (0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                                >> 8U))))) {
                    vlTOPp->mordor__DOT__data_path__DOT__alu 
                        = (0xffffeffeU & vlTOPp->mordor__DOT__data_path__DOT__reg_a);
                } else {
                    if ((0x12U == (0x1fU & (IData)(
                                                   (vlTOPp->mordor__DOT__ucode 
                                                    >> 8U))))) {
                        vlTOPp->mordor__DOT__data_path__DOT__alu 
                            = vlTOPp->mordor__DOT__data_path__DOT__exception_target;
                    }
                }
            }
        }
    }
    VL_WRITEF("A, B, op, ALU = %x %x %2# %x\n",32,vlTOPp->mordor__DOT__data_path__DOT__reg_a,
              32,vlTOPp->mordor__DOT__data_path__DOT__reg_b,
              5,(0x1fU & (IData)((vlTOPp->mordor__DOT__ucode 
                                  >> 8U))),32,vlTOPp->mordor__DOT__data_path__DOT__alu);
    VL_WRITEF("PC = %x\n",32,vlTOPp->mordor__DOT__data_path__DOT__regfile
              [0x20U]);
    vlTOPp->mordor__DOT__data_path__DOT__bus = (((1U 
                                                  & (IData)(
                                                            (vlTOPp->mordor__DOT__ucode 
                                                             >> 0x13U)))
                                                  ? vlTOPp->mordor__DOT__data_path__DOT__immediate
                                                  : 
                                                 ((1U 
                                                   & (IData)(
                                                             (vlTOPp->mordor__DOT__ucode 
                                                              >> 0x15U)))
                                                   ? vlTOPp->mordor__DOT__data_path__DOT__alu
                                                   : 
                                                  ((IData)(vlTOPp->mordor__DOT__data_path__DOT__regread)
                                                    ? 
                                                   vlTOPp->mordor__DOT__data_path__DOT__regfile
                                                   [vlTOPp->mordor__DOT__data_path__DOT__reg_addr]
                                                    : 
                                                   ((IData)(vlTOPp->mordor__DOT__data_path__DOT__memread)
                                                     ? vlTOPp->mordor__DOT____Vcellout__memory__data_output
                                                     : 0U)))) 
                                                & ((1U 
                                                    & (IData)(
                                                              (vlTOPp->mordor__DOT__ucode 
                                                               >> 0x13U)))
                                                    ? 0xffffffffU
                                                    : 
                                                   ((1U 
                                                     & (IData)(
                                                               (vlTOPp->mordor__DOT__ucode 
                                                                >> 0x15U)))
                                                     ? 0xffffffffU
                                                     : 
                                                    ((IData)(vlTOPp->mordor__DOT__data_path__DOT__regread)
                                                      ? 0xffffffffU
                                                      : 
                                                     ((IData)(vlTOPp->mordor__DOT__data_path__DOT__memread)
                                                       ? 0xffffffffU
                                                       : 0U)))));
    vlTOPp->__Vtableidx1 = (((0U == vlTOPp->mordor__DOT__data_path__DOT__alu) 
                             << 4U) | ((((0U == (IData)(vlTOPp->mordor__DOT__memory__DOT__mem_counter))
                                          ? 0U : 1U) 
                                        << 3U) | (7U 
                                                  & (IData)(
                                                            (vlTOPp->mordor__DOT__ucode 
                                                             >> 0xdU)))));
    vlTOPp->mordor__DOT__control_section__DOT__upc_sel 
        = vlTOPp->__Vtable1_mordor__DOT__control_section__DOT__upc_sel
        [vlTOPp->__Vtableidx1];
    vlTOPp->mordor__DOT__control_section__DOT__upc_next 
        = (0xffU & ((2U & (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_sel))
                     ? ((1U & (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_sel))
                         ? (IData)(vlTOPp->mordor__DOT__upc)
                         : ((IData)(1U) + (IData)(vlTOPp->mordor__DOT__upc)))
                     : ((1U & (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_sel))
                         ? (IData)(vlTOPp->mordor__DOT__ucode)
                         : (IData)(vlTOPp->mordor__DOT__control_section__DOT__upc_decode))));
}

void Vmordor::_eval(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_eval\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->clock)) & (IData)(vlTOPp->__Vclklast__TOP__clock))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vmordor::_eval_initial(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_eval_initial\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vmordor::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::final\n"); );
    // Variables
    Vmordor__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_final_TOP(vlSymsp);
}

void Vmordor::_eval_settle(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_eval_settle\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vmordor::_change_request(Vmordor__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_change_request\n"); );
    Vmordor* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmordor::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
}
#endif  // VL_DEBUG

void Vmordor::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmordor::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    mordor__DOT__ir = VL_RAND_RESET_I(32);
    mordor__DOT__mem_addr = VL_RAND_RESET_I(32);
    mordor__DOT__mem_data_input = VL_RAND_RESET_I(32);
    mordor__DOT__upc = VL_RAND_RESET_I(8);
    mordor__DOT__ucode = VL_RAND_RESET_Q(40);
    mordor__DOT____Vcellout__memory__data_output = VL_RAND_RESET_I(32);
    mordor__DOT__data_path__DOT__alu = VL_RAND_RESET_I(32);
    mordor__DOT__data_path__DOT__reg_a = VL_RAND_RESET_I(32);
    mordor__DOT__data_path__DOT__reg_b = VL_RAND_RESET_I(32);
    mordor__DOT__data_path__DOT__exception_target = VL_RAND_RESET_I(32);
    mordor__DOT__data_path__DOT__reg_addr = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
            mordor__DOT__data_path__DOT__regfile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    mordor__DOT__data_path__DOT__regread = VL_RAND_RESET_I(1);
    mordor__DOT__data_path__DOT__memread = VL_RAND_RESET_I(1);
    mordor__DOT__data_path__DOT__bus = VL_RAND_RESET_I(32);
    mordor__DOT__data_path__DOT__immediate = VL_RAND_RESET_I(32);
    mordor__DOT__control_section__DOT__upc_next = VL_RAND_RESET_I(8);
    mordor__DOT__control_section__DOT__upc_decode = VL_RAND_RESET_I(8);
    mordor__DOT__control_section__DOT__upc_sel = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            mordor__DOT__memory__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    mordor__DOT__memory__DOT__mem_counter = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            mordor__DOT__code__DOT__mem[__Vi0] = VL_RAND_RESET_Q(40);
    }}
    __Vtableidx1 = 0;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[0] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[1] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[2] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[3] = 0U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[4] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[5] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[6] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[7] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[8] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[9] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[10] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[11] = 0U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[12] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[13] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[14] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[15] = 3U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[16] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[17] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[18] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[19] = 0U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[20] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[21] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[22] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[23] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[24] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[25] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[26] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[27] = 0U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[28] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[29] = 1U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[30] = 2U;
    __Vtable1_mordor__DOT__control_section__DOT__upc_sel[31] = 3U;
}
