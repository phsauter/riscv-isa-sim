sreg_t res = RD;
sreg_t val = zext_xlen(RS1);
reg_t first = insn.p_zimm5();
reg_t upto = insn.p_Luimm5();

int offset = first+upto-31;
if(offset < 0) {
    offset = 0;
}

reg_t bit_mask = ( (((reg_t)1<<upto)<<1) -1 );

reg_t set_mask = (bit_mask << first) & (val << (first-offset));
reg_t clr_mask = ~(bit_mask << first) | (val << (first-offset));

res |= set_mask;
res &= clr_mask;

WRITE_RD(sext_xlen(res));