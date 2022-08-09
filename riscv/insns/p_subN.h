sreg_t term1 = sext_xlen(RS1);
sreg_t term2 = sext_xlen(RS2);
int norm = insn.p_Luimm5();

sreg_t res = (term1 - term2) >> norm;

WRITE_RD(sext_xlen(res));
