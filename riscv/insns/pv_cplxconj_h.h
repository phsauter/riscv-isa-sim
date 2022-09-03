reg_t src1 = RS1;
reg_t res;

// uint16_t zero-extends to uint32_t, which is needed
uint16_t real = src1;
int16_t imag = (src1 >> 16);

imag = -imag;
res = (imag << 16) | real;

WRITE_RD(sext_xlen(res));
