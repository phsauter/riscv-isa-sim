sreg_t val = sext_xlen(RS1);
reg_t first = zextr(RS2, 4, 0); // rs1[4:0]
reg_t upto = zextr(RS2, 9, 5);  // rs1[9:5]

reg_t set_mask = ( (((reg_t)1<<upto)<<1) -1 ) << first;
reg_t res = set_mask | val;

WRITE_RD(sext_xlen(res));