reg_t selector = insn.p_zimm6();;

reg_t sel2 = (selector >> 4)%4;
reg_t sel1 = (selector >> 2)%4;
reg_t sel0 = selector%4;

reg_t byte3 = RS1_B(1);
reg_t byte2 = RS1_B(sel2);
reg_t byte1 = RS1_B(sel1);
reg_t byte0 = RS1_B(sel0);

reg_t res = (byte3 << 24) | (byte2 << 16) | (byte1 << 8) | byte0;

WRITE_RD(sext_xlen(res));

