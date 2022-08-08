reg_t val = zext_xlen(RS1);

#ifdef __GNUC__
  // "Returns the number of 1-bits in x."
  reg_t cnt = __builtin_popcount(val);
#elif
  reg_t cnt = 0;
  for(cnt = 0; val != 0x00; ++cnt)
  {
    val &= val - 1;
  }
#endif
WRITE_RD(cnt);
