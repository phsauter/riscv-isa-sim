sreg_t term1 = sext_xlen(RD);
sreg_t term2 = sext_xlen(RS1);
int norm =    RS2%0x20; // rs[4:0]

sreg_t res = (term1 + term2) >> norm;

WRITE_RD(sext_xlen(res));
