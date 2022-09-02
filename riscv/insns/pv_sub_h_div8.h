// Todo: explicit use of SIMD insns (ie xsimd lib) would be better

union simd_reg src1 = {.reg = RS1};
union simd_reg src2 = {.reg = RS2};
union simd_reg res;

int16_t temp;

for(int i=0; i<(64/e16); i++)
{
    // (src1.h[i] - src2.h[i]) >> 3 doesn't work as shift
    // will be performed in int32 (using overflows from add)
    temp = src1.h[i] - src2.h[i];
    res.h[i] = temp >> 3;
}

WRITE_RD(sext_xlen(res.sreg));

