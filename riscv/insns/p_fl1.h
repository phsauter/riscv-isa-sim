reg_t val = zext_xlen(RS1);;
reg_t cnt;

#ifdef __GNUC__
  if(val) {
    // "Returns the number of leading 0-bits in x" x=0 -> undef
    cnt = 31 - __builtin_clz(val);
  } else {
    cnt = 32;
  }
#elif
  if(val == 0) {
    cnt = 32; // rs1 = 0 -> rd = 0, not 32
  } else {
    // log2() from standfords bithacks (find highest '1')
    while (val >>= 1)
    {
      cnt++;
    }
  }
#endif

WRITE_RD(cnt);
