union simd_reg src1 = {.reg = RS1};
// replicate lowest element in second operand
union simd_reg src2 = {.sreg = ((insn.p_simm6() & 0x0FF)*0x0101010101010101)};
union simd_reg res;

for(int i=0; i<(64/e8); i++)
{
    res.b[i] = (src1.b[i] != src2.b[i]);
}

WRITE_RD(sext_xlen(res.sreg));