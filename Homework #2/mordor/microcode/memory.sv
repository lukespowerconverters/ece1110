`ifndef DEFS_DONE
   `define DEFS_DONE

`include "constants.svh"

`endif

module memory(
    input logic clk,
/* verilator lint_off UNUSED */
    input logic [31:0] address,
/* verilator lint_on UNUSED */
    input logic [1:0][1:0][7:0] data_input,
    output logic [1:0][1:0][7:0] data_output,
    input logic mem_ld,
    input logic mem_wr,
    input [2:0] mt,
    output logic busy,
    input logic reset_n
    );

//    [shw][sby][dat]    [sw   ]
logic [1:0][1:0][7:0] mem[255:0];
logic [7:0] word_addr;
//logic [31:0] mem_output;

mem_state_type mem_counter;

assign word_addr = address[9:2];

    always_ff @(negedge clk)
    begin
        if (mem_counter == MEM_DONE)
            if (mem_wr) // store
            unique case (mt)
	  default: mem[word_addr] <= data_input;
          MT_W: mem[word_addr] <= data_input; // sw 
          MT_H: mem[word_addr][address[1]] <= data_input[address[1]];
          MT_B: mem[word_addr][address[1]][address[0]] <= data_input[0][0];
          MT_HU: mem[word_addr][address[1]] <= data_input[address[1]];
          MT_BU: mem[word_addr][address[1]][address[0]] <= data_input[0][0];
            endcase
            else
    	begin
    	    data_output <= 0; // in case it's smaller than a word
    	    unique case(mt) // load
	  default: data_output <= mem[word_addr];
          MT_W: data_output <= mem[word_addr]; // lw 
          MT_H: data_output[0] <= mem[word_addr][address[1]];
          MT_B: data_output[0][0] <= mem[word_addr][address[1]][address[0]];
          MT_HU: data_output[address[1]] <= mem[word_addr][address[1]];
          MT_BU: data_output[address[1]][0] <= mem[word_addr][address[1]][address[0]];
            endcase
    	end
    end

    always_ff @(negedge clk)
    begin
        mem_counter <= (mem_ld) ? MEM_START :
                       ((mem_counter >= MEM_START) && (mem_counter < MEM_DONE)) ? mem_counter.next
                       : MEM_WAIT;
    end

    always_comb
    begin
        if (!reset_n)
        begin
            $readmemh("program.hex", mem);
        end
        busy = (mem_counter == MEM_WAIT) ? 0 : 1;
    end

    final begin
        for (int i=0; i<80; i += 4)
            $display("%2d: %x, %2d: %x, %2d: %x, %2d: %x", i, mem[i], i+1, mem[i+1], i+2, mem[i+2], i+3, mem[i+3]);
    end

endmodule
