// Todo: explicit use of SIMD insns (ie xsimd lib) would be better

union simd_reg src1 = {.reg = RS1};
// replicate lowest element in second operand
union simd_reg src2 = {.reg = ((RS2 & 0x0FFFF)*0x0001000100010001)};
union simd_reg res;

for(int i=0; i<(64/e16); i++)
{
    res.h[i] = (src1.hu[i] > src2.hu[i]);
}

WRITE_RD(sext_xlen(res.sreg));