`ifndef DEFS_DONE
   `define DEFS_DONE

`include "constants.h"

`endif

`include "decode.svh"

module decode(
/* verilator lint_off UNUSED */
    input logic [31:0] ir,
/* verilator lint_on UNUSED */
    output logic [7:0] udecode
    );

logic [4:0] opcode;
logic [2:0] funct3;
logic [6:0] funct7;

assign opcode = ir[6:2];
assign funct3 = ir[14:12];
assign funct7 = ir[31:25];

always_comb
    begin
        case (opcode)
            5'h00: // load
            case (funct3)
                0: udecode = LB;
                1: udecode = LH;
                2: udecode = LW;
                4: udecode = LBU;
                5: udecode = LHU;
                default: udecode = EBREAK;
            endcase
            5'h03: udecode = EBREAK; // fence
            5'h04: // ALU
            case (funct3)
                0: udecode = ADDI;
                1: udecode = SLLI;
                2: udecode = SLTI;
                3: udecode = SLTIU;
                4: udecode = XORI;
                5: udecode = (funct7 == 0)? SRLI : SRAI;
                6: udecode = ORI;
                7: udecode = ANDI;
            endcase
            5'h05: udecode = AUIPC;
            5'h08: // store
            case (funct3)
                0: udecode = SB;
                1: udecode = SH;
                2: udecode = SW;
                default: udecode = EBREAK;
            endcase
            5'h0c: // ALU
            case (funct3)
                0: udecode = (funct7 == 0)? ADD: SUB;
                1: udecode = SLL;
                2: udecode = SLT;
                3: udecode = SLTU;
                4: udecode = XOR;
                5: udecode = (funct7 == 0)? SRL : SRA;
                6: udecode = OR;
                7: udecode = AND;
            endcase
            5'h0d: udecode = LUI;
            5'h10: udecode = EXTRA; // Extra, extra read all about it
            5'h14: udecode = EBREAK; // floating point
            5'h18:  // branch
            case (funct3)
                0: udecode = BEQ;
                1: udecode = BNE;
                4: udecode = BLT;
                5: udecode = BGE;
                6: udecode = BLTU;
                7: udecode = BGEU;
                default: udecode = EBREAK;
            endcase
            5'h19: udecode = JALR;
            5'h1b: udecode = JAL;
            5'h1c: // ecall/ebreak/csr
            case (funct3)
                0: udecode = (funct7 == 0)? ECALL: EBREAK;
                1: udecode = CSRRW;
                2: udecode = CSRRS;
                3: udecode = CSRRC;
                4: udecode = EBREAK;
                5: udecode = CSRRWI;
                6: udecode = CSRRSI;
                7: udecode = CSRRC;
            endcase
	    5'h1f: begin udecode = EHALT; $finish; end // halt (and catch fire)
            default: udecode = EBREAK;
        endcase
    end

endmodule

