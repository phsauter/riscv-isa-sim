sreg_t res = RD;
sreg_t val = zext_xlen(RS1);
reg_t first = zextr(RS2, 4, 0); // rs1[4:0]
reg_t upto = zextr(RS2, 9, 5);  // rs1[9:5]

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
