
`ifndef DEFS_DONE
   `define DEFS_DONE

`include "constants.svh"

`endif

module microcode(
    input logic reset_n,
    input logic [7:0] address,
    output logic [39:0] data_out
    );

logic [39:0] mem[256]; // ROM

always_ff
begin
    data_out = (reset_n) ? mem[address] : 0;
end

initial begin
        $readmemh("ucode.hex", mem);
    end

endmodule

