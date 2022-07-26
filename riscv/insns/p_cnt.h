reg_t val = zext_xlen(RS1);
reg_t cnt = 0;

for(cnt = 0; val != 0x00; ++cnt)
{
  val &= val - 1;
}
WRITE_RD(cnt);
