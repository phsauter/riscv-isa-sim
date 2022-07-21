uint8_t temp;
uint32_t simd_rd = 0;

for(int i = xlen/8 - 1; i >= 0; i--){
  temp = zext8(RS1_B(i)) <= zext8(RS2_B(0)) ? RS1_B(i) : RS2_B(0);
  simd_rd <<= 8;
  simd_rd += (uint32_t)temp & 0x000000FF;
}
WRITE_RD(sext_xlen(simd_rd));
