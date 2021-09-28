
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

always_comb
begin
    if (reset_n) data_out = mem[address];
end

always_comb
    if (!reset_n)
    begin
        $readmemh("ucode.hex", mem);
    end

endmodule

