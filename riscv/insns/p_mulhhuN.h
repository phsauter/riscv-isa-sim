reg_t mul1 = zext16(RS1_H(1));
reg_t mul2 = zext16(RS2_H(1));
int norm = insn.p_Luimm5();

reg_t res = (mul1 * mul2) >> norm;

WRITE_RD(sext_xlen(res));   // this is not a mistake, it needs to be signed here because
                            // Spike works with 64bit register representations internally.
                            // And it expects the results to be signed (see eg. slli)