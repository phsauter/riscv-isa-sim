sreg_t mul1 = sext16(RS1_H(0));
sreg_t mul2 = sext16(RS2_H(0));
int norm = insn.p_Luimm5();

sreg_t res = (mul1 * mul2) >> norm;

WRITE_RD(sext_xlen(res));
