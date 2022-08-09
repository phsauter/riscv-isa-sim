sreg_t mul1 = sext16(RS1_H(1));
sreg_t mul2 = sext16(RS2_H(1));
int norm = insn.p_Luimm5();
uint halfbit = ((uint)0x01 << (norm))/2; // for rounding

sreg_t res = ((mul1 * mul2) + halfbit) >> norm;

WRITE_RD(sext_xlen(res));
