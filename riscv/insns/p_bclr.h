sreg_t val = sext_xlen(RS1);
reg_t first = insn.p_zimm5();
reg_t upto = insn.p_Luimm5();

reg_t bit_mask = ( (((reg_t)1<<upto)<<1) -1 ) << first;
reg_t res = ~bit_mask & val;

WRITE_RD(sext_xlen(res));