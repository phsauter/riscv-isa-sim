reg_t val = zext_xlen(RS1);
reg_t rot = zext_xlen(RS2)%32;

reg_t res = (val >> rot) | (((val << 32) >> rot));

WRITE_RD(sext_xlen(res));
