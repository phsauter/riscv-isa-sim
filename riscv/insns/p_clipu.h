sreg_t clipu_upper = insn.p_zimm5() ? ((1 << (insn.p_zimm5() - 1)) - 1) : 0;

if(sreg_t(RS1) <= 0)
  WRITE_RD(0);
else if(sreg_t(RS1) >= clipu_upper)
  WRITE_RD(clipu_upper);
else
  WRITE_RD(sreg_t(RS1));
