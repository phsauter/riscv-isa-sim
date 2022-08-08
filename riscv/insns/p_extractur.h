sreg_t val = zext_xlen(RS1);
reg_t first = zextr(RS2, 4, 0); // rs1[4:0]
reg_t upto = zextr(RS2, 9, 5);  // rs1[9:5]

sreg_t res = val >> first;
res = vzext(res, upto+1);

WRITE_RD(sext_xlen(res));