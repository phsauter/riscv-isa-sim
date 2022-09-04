reg_t val = sext_xlen(RS1);;
reg_t cnt = 0;

#ifdef __GNUC__
  if(val) {
    // "Returns the number of leading redundant sign bits"
    cnt = __builtin_clrsb(val) +1;
  } else {
    cnt = 0; // rs1 = 0 -> rd = 0, not 32
  }
#else
  if(val != 0x00) // rs1 = 0 -> rd = 0, not 32
  {
    if(val >= ((reg_t)1 << 31)) {
      // turn leading 1s into leading 0s
      val = ~val;
    }
    val <<= 1; // to distinguish -1 from -2

    // modified log2() from standfords bithacks (find highest '1')
    const unsigned int b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
    const unsigned int S[] = {1, 2, 4, 8, 16};
    for (int i = 4; i >= 0; i--)
    {
      if (val & b[i])
      {
        val >>= S[i];
        cnt |= S[i];
      } 
    }

    cnt = 32 - cnt; // pos of MSB+1 to #leading bits
  }

#endif

WRITE_RD(cnt);
