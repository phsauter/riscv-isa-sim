// Todo: explicit use of SIMD insns (ie xsimd lib) would be better

union simd_reg src1 = {.reg = RS1};
union simd_reg src2 = {.reg = RS2};
union simd_reg res;

for(int i=0; i<(64/e16); i++)
{
    res.h[i] = (src1.h[i] >= src2.h[i]);
}

WRITE_RD(sext_xlen(res.sreg));

