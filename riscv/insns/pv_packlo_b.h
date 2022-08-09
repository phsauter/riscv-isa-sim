reg_t src1 = RS1_B(0);
reg_t src2 = RS2_B(0);
reg_t res  = RD & 0xFFFF0000;

res |= (src1 << 8) | src2;

WRITE_RD(sext_xlen(res));

