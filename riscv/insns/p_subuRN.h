reg_t term1 = zext_xlen(RS1);
reg_t term2 = zext_xlen(RS2);
int norm = insn.p_Luimm5();
uint halfbit = ((uint)0x01 << (norm))/2; // for rounding

reg_t res = ((term1 - term2) + halfbit) >> norm;

WRITE_RD(sext_xlen(res));   // this is not a mistake, it needs to be signed here because
                            // Spike works with 64bit register representations internally.
                            // And it expects the results to be signed (see eg. slli)