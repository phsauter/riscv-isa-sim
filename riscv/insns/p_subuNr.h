reg_t term1 = zext_xlen(RD);
reg_t term2 = zext_xlen(RS1);
int norm =    RS2%0x20; // rs[4:0]

reg_t res = (term1 - term2) >> norm;

WRITE_RD(sext_xlen(res));   // this is not a mistake, it needs to be signed here because
                            // Spike works with 64bit register representations internally.
                            // And it expects the results to be signed (see eg. slli)