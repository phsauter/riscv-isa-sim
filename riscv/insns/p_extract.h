sreg_t val = sext_xlen(RS1);
reg_t first = insn.p_zimm5();
reg_t upto = insn.p_Luimm5();

sreg_t res = val >> first;
res = vsext(res, upto+1);

WRITE_RD(res);
