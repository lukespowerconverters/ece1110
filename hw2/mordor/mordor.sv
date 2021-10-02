/*
 * Top level
 */
`ifndef DEFS_DONE
   `define DEFS_DONE

`include "constants.svh"

`endif

module mordor(
    input logic clock,
    input logic reset_n
    );

    logic [31:0] ir;
    logic ld_ir;
    logic [2:0] mt;
    logic [2:0] csr;
    logic [2:0] reg_sel;
    logic reg_wr;
    logic reg_en;
    logic a_ld;
    logic b_ld;
    logic [4:0] alu_op;
    logic alu_en;
    logic mem_ld;
    logic mem_wr;
    logic mem_en;
    logic imm_en;
    logic [31:0] mem_addr;
    logic [31:0] mem_data_input;
    logic [31:0] mem_data_output;
    logic mem_is_busy;
    logic alu_zero;
    logic [2:0] imm_sel;
    logic [7:0] upc;
    logic [39:0] ucode;

dpath data_path (
    .csr (csr),
    .ir_ld (ld_ir),
    .ir (ir),
    .reg_sel (reg_sel),
    .reg_wr (reg_wr),
    .reg_en (reg_en),
    .a_ld (a_ld),
    .b_ld (b_ld),
    .alu_op (alu_op),
    .alu_en (alu_en),
    .mem_ld (mem_ld),
    .mem_wr (mem_wr),
    .mem_en (mem_en),
    .imm_en (imm_en),
    .imm_sel (imm_sel),
    .mem_addr (mem_addr),
    .mem_data_input (mem_data_input),
    .mem_data_output (mem_data_output),
    .alu_zero (alu_zero),
    .reset_n (reset_n),
    .clk (clock)
    );

cpath control_section (
// decoded ucode fields
    .mt (mt),
    .csr (csr),
    .ir_ld (ld_ir),
    .ir (ir),
    .reg_sel (reg_sel),
    .reg_wr (reg_wr),
    .reg_en (reg_en),
    .a_ld (a_ld),
    .b_ld (b_ld),
    .alu_op (alu_op),
    .alu_en (alu_en),
    .mem_ld (mem_ld),
    .mem_wr (mem_wr),
    .mem_en (mem_en),
    .imm_en (imm_en),
    .imm_sel (imm_sel),
// memory
    .mem_is_busy (mem_is_busy),
// microcode
    .upc (upc),
    .uword (ucode),
// all others
    .alu_zero (alu_zero),
    .reset_n (reset_n),
    .clk (clock)
    );

memory memory (
    .clk (clock),
    .address (mem_addr),
    .mem_ld (mem_ld),
    .mem_wr (mem_wr),
    .mt (mt),
    .data_input (mem_data_input),
    .data_output (mem_data_output),
    .busy (mem_is_busy)
    );

microcode code (
    .reset_n (reset_n),
    .address (upc),
    .data_out (ucode)
    );

endmodule
