reg_t src1 = RS1_H(1);
reg_t src2 = RS2_H(1);

reg_t res = (src1 << 16) | src2;

WRITE_RD(sext_xlen(res));

