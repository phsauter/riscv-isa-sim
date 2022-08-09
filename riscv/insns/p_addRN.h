sreg_t term1 = sext_xlen(RS1);
sreg_t term2 = sext_xlen(RS2);
int norm = insn.p_Luimm5();
uint halfbit = ((uint)0x01 << (norm))/2; // for rounding

sreg_t res = ((term1 + term2) + halfbit) >> norm;

WRITE_RD(sext_xlen(res));
