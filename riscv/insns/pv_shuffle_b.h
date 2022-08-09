reg_t selector = RS2;

reg_t sel3 = (selector >> 24)%4;
reg_t sel2 = (selector >> 16)%4;
reg_t sel1 = (selector >> 8)%4;
reg_t sel0 = selector%4;

reg_t byte3 = RS1_B(sel3);
reg_t byte2 = RS1_B(sel2);
reg_t byte1 = RS1_B(sel1);
reg_t byte0 = RS1_B(sel0);

reg_t res = (byte3 << 24) | (byte2 << 16) | (byte1 << 8) | byte0;

WRITE_RD(sext_xlen(res));

