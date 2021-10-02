/*
 * Microprocessor data path
 */

`ifndef DEFS_DONE
   `define DEFS_DONE

`include "constants.svh"

`endif

module dpath(
    output logic [31:0] ir,
/* verilator lint_off UNUSED */
    input logic [2:0] csr,
/* verilator lint_on UNUSED */
    input logic ir_ld,
    input logic [2:0] reg_sel,
    input logic reg_wr,
    input logic reg_en,
    input logic a_ld,
    input logic b_ld,
    input logic [4:0] alu_op,
    input logic alu_en,
    input logic mem_ld,
    input logic mem_wr,
    input logic mem_en,
    input logic imm_en,
    input logic [2:0] imm_sel,
    output logic [31:0] mem_addr,
    output logic [31:0] mem_data_input,
    input logic [31:0] mem_data_output,
    output logic alu_zero,
    input logic reset_n,
    input logic clk
    );

// forward declarations
    logic [31:0] alu;
    logic [31:0] reg_a;
    logic [31:0] reg_b;
/* verilator lint_off UNDRIVEN */
    logic [31:0] exception_target;
/* verilator lint_on UNDRIVEN */

    // Register File (Single Port)
    // also holds the PC register
    logic [RS1_MSB-RS1_LSB:0] rs1;
    logic [RS2_MSB-RS2_LSB:0] rs2;
    logic [RD_MSB-RD_LSB:0] rd;

    assign rs1 = ir[RS1_MSB:RS1_LSB];
    assign rs2 = ir[RS2_MSB:RS2_LSB];
    assign rd  = ir[RD_MSB:RD_LSB];
    
    logic [5:0] reg_addr;

    always_comb
      case (reg_sel)
                  RS_PC:  reg_addr = PC_IDX;
                  RS_RD:  reg_addr = {1'b0,rd};
                  RS_RS1: reg_addr = {1'b0,rs1};
                  RS_RS2: reg_addr = {1'b0,rs2};
                  RS_X0:  reg_addr = X0;
                  RS_CA:  reg_addr = X0;
                  RS_CR:  reg_addr = X0;
      endcase

    //32 x-registers, 1 pc-register
    logic [31:0] regfile[64];
    //Control Status Registers

    logic regwrite, regread, memread;
    assign regwrite = reg_en & reg_wr & (reg_addr != 0);// register write, ignore register 0
    assign regread = reg_en & ~reg_wr & (reg_sel <= RS_CR);
    assign memread = mem_en & ~mem_wr;

    // The Bus
    // (this is a bus-based RISCV implementation, so all data movement goes across this logic)
    logic [31:0] bus;

    always_comb
    begin
    // bus writes
        bus = (imm_en) ? immediate :
               (alu_en) ? alu :
               (regread) ? regfile[reg_addr] :
               (memread) ? mem_data_output : 
               32'hzzzzzzzz;
//       $display("reg_en, reg_wr, imm_sel, imm_en = %x %x %x %x [%x]", reg_en ,reg_wr , imm_sel, imm_en, immediate);
       $display("A, B, op, ALU = %x %x %d %x", reg_a ,reg_b , alu_op, alu);
       $display("PC = %x", regfile[PC_IDX]);
    end

    always_ff @(negedge clk)
    begin
    // bus reads
        if (regwrite) regfile[reg_addr] <= bus;
        if (ir_ld) ir <= (!reset_n) ? 0 : bus;
        if (a_ld) reg_a <= (!reset_n) ? 0 : bus;
        if (b_ld) reg_b <= (!reset_n) ? 0 : bus;
        if (mem_ld) mem_addr <= bus;
        if (mem_wr) mem_data_input <= bus;
    end

    // ALU
    logic [4:0] alu_shamt;
    assign alu_shamt = reg_b[4:0];

    always_comb
        unique case (alu_op)
           ALU_COPY_A:  alu = reg_a;
           ALU_COPY_B:  alu = reg_b;
           ALU_INC_A_1: alu = (reg_a  +  1);
           ALU_DEC_A_1: alu = (reg_a  -  1);
           ALU_INC_A_4: alu = (reg_a  +  4);
           ALU_DEC_A_4: alu = (reg_a  -  4);
           ALU_ADD:     alu = (reg_a  +  reg_b);
           ALU_SUB:     alu = (reg_a  -  reg_b);
           ALU_SLL:     alu = (reg_a << alu_shamt);
           ALU_SRL:     alu = (reg_a >> alu_shamt);
           ALU_SRA:     alu = (reg_a >>> alu_shamt);
           ALU_AND:     alu = (reg_a & reg_b);
           ALU_OR:      alu = (reg_a | reg_b);
           ALU_XOR:     alu = (reg_a ^ reg_b);
           ALU_SLT:     alu = {31'b0,(reg_a < reg_b)};
           ALU_SLTU:    alu = unsigned'({31'b0,(reg_a < reg_b)});
           ALU_INIT_PC: alu = START_ADDR;
           ALU_MASK_12: alu = (reg_a & ~(1<<12)-1);
           ALU_EVEC:    alu = exception_target;
        endcase

    // Output Signals to the Control Path
    assign alu_zero = (alu == 0);

    // IR Immediate
    logic [31:0] immediate;
    always_comb
    begin
        unique case (imm_sel)
              IS_I:  immediate = {(ir[31] ? 20'hfffff : 20'h00000), ir[31:20]}; // LD, ALU
              IS_S:  immediate = {(ir[31] ? 20'hfffff : 20'h00000), ir[31:25], ir[11:7]}; // Stores
              IS_U:  immediate = {ir[31:12], 12'h0}; // LUI
              IS_J:  immediate = {12'b0, ir[19:12], ir[20], ir[30:21], 1'b0}; // Jump, not sign extended
              IS_B:  immediate = {(ir[7] ? 20'hfffff : 20'h00000), ir[7], ir[30:25], ir[11:8], 1'b0}; // branch
        endcase
    end

    final begin
        for (int i=0; i<32; i += 4) // was $size(regfile)
            $display("%2d: %x, %2d: %x, %2d: %x, %2d: %x", i, regfile[i], i+1, regfile[i+1], i+2, regfile[i+2], i+3, regfile[i+3]);
    end

endmodule
