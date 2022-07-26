sreg_t mul1 = sext16(RS1_H(1));
sreg_t mul2 = sext16(RS2_H(1));
sreg_t acc = sext_xlen(P_RS3);
int norm = insn.p_Luimm5();
uint halfbit = ((uint)0x01 << (norm))/2; // for rounding

acc = ((mul1 * mul2) + acc + halfbit) >> norm;

WRITE_RD(sext_xlen(acc));
