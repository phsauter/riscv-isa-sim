reg_t val = zext_xlen(RS1);
reg_t cnt;

#ifdef __GNUC__
    // "Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero. "
    cnt = __builtin_ffs(val);
    if(cnt == 0) {
      cnt = 32; // rs = 0 -> rd = 32
    } else {
      cnt--;
    }
#else
  // count trailing zero bits from standfords bithacks
  cnt = 32;
  val &= -signed(val);
  if (val) cnt--;
  if (val & 0x0000FFFF) cnt -= 16;
  if (val & 0x00FF00FF) cnt -= 8;
  if (val & 0x0F0F0F0F) cnt -= 4;
  if (val & 0x33333333) cnt -= 2;
  if (val & 0x55555555) cnt -= 1;
#endif

WRITE_RD(cnt);
