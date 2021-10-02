/*
 * Microprocessor control path
 */

`ifndef DEFS_DONE
   `define DEFS_DONE

`include "constants.svh"

`endif

module cpath(
    input logic [31:0] ir, // from data path
// decoded ucode fields
    output logic ir_ld,
    output logic [2:0] mt,
    output logic [2:0] csr,
    output logic [2:0] reg_sel,
    output logic reg_wr,
    output logic reg_en,
    output logic a_ld,
    output logic b_ld,
    output logic [4:0] alu_op,
    output logic alu_en,
    output logic mem_ld,
    output logic mem_wr,
    output logic mem_en,
    output logic imm_en,
    output logic [2:0] imm_sel,
// memory
    input logic mem_is_busy,
// microcode interface
    output logic [7:0] upc,
    input logic [39:0] uword,
// all others
    input logic alu_zero,
    input logic reset_n,
    input logic clk
    );

decode decoder(
    .ir (ir),
    .udecode (upc_decode)
    );

// Micro-PC State Register
    logic [7:0] upc_target;
    logic [7:0] upc_next;
    logic [7:0] upc_decode;

    always_comb
    begin
        mem_wr = uword[37];
        mem_ld = uword[36];
        mt = uword[35:33];
        csr = uword[32:30];
        reg_sel = uword[29:27];
        ir_ld = uword[26];
        reg_wr = uword[25];
        reg_en = uword[24];
        a_ld = uword[23];
        b_ld = uword[22];
        alu_en = uword[21];
        mem_en = uword[20];
        imm_en = uword[19];
        imm_sel = uword[18:16];
        ubr = uword[15:13];
        alu_op = uword[12:08];
        upc_target = uword[7:0];
    end

    // Micro-PC State Logic
    logic [1:0] upc_sel;
    logic [2:0] ubr;

    always_comb
    begin
        case (ubr) // Missing UBR_Z (used by CSR)
          UBR_N : upc_sel = UPC_NEXT;
          UBR_D : upc_sel = UPC_DISPATCH;
          UBR_J : upc_sel = UPC_ABSOLUTE;
          UBR_EZ: upc_sel = alu_zero ? UPC_ABSOLUTE : UPC_NEXT;
          UBR_NZ: upc_sel = ~alu_zero ? UPC_ABSOLUTE : UPC_NEXT;
          UBR_S : upc_sel = mem_is_busy ? UPC_CURRENT : UPC_NEXT; // S is for Spin
          default: upc_sel = UPC_NEXT;
        endcase
    end
    always_comb
    begin
        case (upc_sel)
          UPC_DISPATCH: upc_next = upc_decode;
          UPC_ABSOLUTE: upc_next = upc_target;
          UPC_NEXT    : upc_next = upc + 1;
          UPC_CURRENT : upc_next = upc;
        endcase
    end

    always_ff @(negedge clk)
    begin
        if (!reset_n) upc <= 0;
        else
        upc <= upc_next;
    end

    always_ff @(negedge clk)
   // Printout every microcycle
   $display("uPC=[%x] uword=[%x] UBR=[%x] RegSel=[%d] InstReg=[%x]",
      upc,
      uword,
      ubr,
      reg_sel,
      ir);

endmodule
