
    // Load IR Register Signal
    localparam LDIR_0  = 0;
    localparam LDIR_1  = 1;
    localparam LDIR_X  = 0;

    // Register File Address Select Signal
    localparam RS_PC   = 0;
    localparam RS_RD   = 1;
    localparam RS_RS1  = 2;
    localparam RS_RS2  = 3;
    localparam RS_CA   = 5;
    localparam RS_CR   = 6;
    localparam RS_X0   = 7;
    localparam RS_X    = 7;

    // Register File Write Signal
    localparam RWR_0   = 0;
    localparam RWR_1   = 1;
    localparam RWR_X   = 0;

    // Register File Enable Signal
    localparam REN_0   = 0;
    localparam REN_1   = 1;
    localparam REN_X   = 0;

    // Load A Register Signal
    localparam LDA_0  = 0;
    localparam LDA_1  = 1;
    localparam LDA_X  = 0;

    // Load B Register Signal
    localparam LDB_0  = 0;
    localparam LDB_1  = 1;
    localparam LDB_X  = 0;

    // ALU Operation Signal
    localparam ALU_COPY_A   = 0;
    localparam ALU_COPY_B   = 1;
    localparam ALU_INC_A_1  = 2;
    localparam ALU_DEC_A_1  = 3;
    localparam ALU_INC_A_4  = 4;
    localparam ALU_DEC_A_4  = 5;
    localparam ALU_ADD      = 6;
    localparam ALU_SUB      = 7;
    localparam ALU_SLL      = 8;
    localparam ALU_SRL      = 9;
    localparam ALU_SRA      = 10;
    localparam ALU_AND      = 11;
    localparam ALU_OR       = 12;
    localparam ALU_XOR      = 13;
    localparam ALU_SLT      = 14;
    localparam ALU_SLTU     = 15;
    localparam ALU_INIT_PC  = 16;
    localparam ALU_MASK_12  = 17;
    localparam ALU_EVEC     = 18;
    localparam ALU_X        = 0;

    // ALU Enable Signal
    localparam AEN_0   = 0;
    localparam AEN_1   = 1;
    localparam AEN_X   = 0;

    localparam LDMA_0  = 0;
    localparam LDMA_1  = 1;
    localparam LDMA_X  = 0;

    // Memory Write Signal
    localparam MWR_0   = 0;
    localparam MWR_1   = 1;
    localparam MWR_X   = 0;

    // Memory Enable Signal
    localparam MEN_0   = 0;
    localparam MEN_1   = 1;
    localparam MEN_X   = 0;

    // Immediate Extend Select
    localparam IS_X   = 0;
    localparam IS_I   = 1;
    localparam IS_S   = 2;
    localparam IS_B   = 3;
    localparam IS_U   = 4;
    localparam IS_J   = 5;
    localparam IS_Z   = 6;

    // Immediate Enable Signal
    localparam IEN_0   = 0;
    localparam IEN_1   = 1;
    localparam IEN_X   = 0;

    // abstract out instruction decode magic numbers
    localparam RD_MSB  = 11;
    localparam RD_LSB  = 7;
    localparam RS1_MSB = 19;
    localparam RS1_LSB = 15;
    localparam RS2_MSB = 24;
    localparam RS2_LSB = 20;
    localparam RS3_MSB = 31;
    localparam RS3_LSB = 27;
  
    localparam CSR_ADDR_MSB = 31;
    localparam CSR_ADDR_LSB = 20;
    localparam CSR_ADDR_SZ = 12;
  
    // location of the fifth bit in the shamt (for checking for illegal ops for SRAIW,etc.)
    localparam SHAMT_5_BIT = 25;
    localparam LONGEST_IMM_SZ = 20;
    localparam X0 = 0;
    localparam RA = 1 ;// return address register

    // uBranch Type
    typedef enum logic [2:0] { UBR_X, UBR_Z, UBR_N, UBR_D, UBR_J, UBR_EZ, UBR_NZ, UBR_S } UBR;

    // Micro-PC State Logic
    typedef enum logic [1:0] {UPC_DISPATCH, UPC_ABSOLUTE, UPC_NEXT, UPC_CURRENT} USEL;

    // Registers
    localparam PC_IDX = 32;   //pc register;

    // Memory Mask Type Signal
    localparam MSK_SZ  = 3;

    localparam START_ADDR = 32'h00000200;

    typedef enum logic [2:0] { MEM_WAIT, MEM_START, MEM_2, MEM_3, MEM_DONE} mem_state_type;
    typedef enum logic [2:0] { MT_W, MT_H, MT_B, MT_HU, MT_BU, MT_Q, MT_X, MT_XX} mem_size;
