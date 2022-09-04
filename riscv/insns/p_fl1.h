reg_t val = zext_xlen(RS1);;
reg_t cnt;

#ifdef __GNUC__
  if(val) {
    // "Returns the number of leading 0-bits in x" x=0 -> undef
    cnt = 31 - __builtin_clz(val);
  } else {
    // rs1 = 0 -> rd = 0, not 32
    cnt = 32;
  }
#else
  if(val){  
    // log2() from standfords bithacks (find highest '1')
    const unsigned int b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
    const unsigned int S[] = {1, 2, 4, 8, 16};
    cnt = 0;
    for (int i = 4; i >= 0; i--)
    {
      if (val & b[i])
      {
        val >>= S[i];
        cnt |= S[i];
      } 
    }
  } else {
    // rs1 = 0 -> rd = 0, not 32
    cnt = 32;
  }
#endif

WRITE_RD(cnt);
