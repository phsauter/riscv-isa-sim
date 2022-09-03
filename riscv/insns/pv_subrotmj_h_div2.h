reg_t src1 = RS1;
reg_t src2 = RS2;
reg_t res;

int16_t real1 = src1;
int16_t imag1 = (src1 >> 16);
int16_t real2 = src2;
int16_t imag2 = (src2 >> 16);

// uint16_t zero-extends to uint32_t, which is needed
uint16_t real = (int16_t)(imag1 - imag2) >> 1;
uint16_t imag = (int16_t)(real2 - real1) >> 1;
res = (imag << 16) | real;

WRITE_RD(sext_xlen(res));

