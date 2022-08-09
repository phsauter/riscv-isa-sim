reg_t selector = insn.p_zimm6();

reg_t h_sel = (selector >> 1)%2;
reg_t l_sel = selector%2;
reg_t hhalf = RS1_H(h_sel);
reg_t lhalf = RS1_H(l_sel);

reg_t res = (hhalf << 16) | lhalf;

WRITE_RD(sext_xlen(res));

