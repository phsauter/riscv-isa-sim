reg_t val = zext_xlen(RS1);
reg_t cnt;

#ifdef __GNUC__
  // "Returns the number of 1-bits in x."
  cnt = __builtin_popcount(val);
#else
  cnt = 0;
  for(cnt = 0; val != 0x00; ++cnt)
  {
    val &= val - 1;
  }
#endif
WRITE_RD(cnt);
