reg_t src1 = RS1_B(0);
reg_t src2 = RS2_B(0);
reg_t res  = RD & 0x0FFFF;

res |= (src1 << 24) | (src2 << 16);

WRITE_RD(sext_xlen(res));

