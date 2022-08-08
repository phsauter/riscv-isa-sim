sreg_t val = sext_xlen(RS1);;
reg_t cnt;

#ifdef __GNUC__
  if(val) {
    // "Returns the number of leading redundant sign bits"
    cnt = __builtin_clrsb(val) +1;
  } else {
    cnt = 0; // rs1 = 0 -> rd = 0, not 32
  }
#elif
  if(val == 0) {
    cnt = 0; // rs1 = 0 -> rd = 0, not 32
  } else {
    if(val > 0) {
      // turn leading 0s into leading 1s
      val = ~val;
    }

    // log2() from standfords bithacks (find highest '1')
    while (val >>= 1)
    {
      cnt++;
    }
  }

#endif

std::cout << "bin: " << std::hex << (__builtin_clrsb(val)) << std::endl;
std::cout << "val: " << std::hex << val << std::endl;
std::cout << "cnt: " << cnt << std::endl;


WRITE_RD(cnt);
