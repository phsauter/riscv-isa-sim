reg_t val = zext_xlen(RS1);
reg_t shift = insn.p_zimm5();
reg_t group = insn.p_Luimm5();
reg_t res;

// using method from: 
// https://graphics.stanford.edu/~seander/bithacks.html#ReverseByteWith64BitsDiv
// with 6bits per block, padded to 8bit spacing
// groups of 2 and 3 bits could be done faster (12bit blocks)

const reg_t mult_masks[3] = {0x208208, 0x1001, 0x2008};
const reg_t and_masks[3] = {0x2240910, 0x3300C, 0x70038};

val <<= shift;

// handle two LSB bits
switch(group)
{
    case 0: // res[1:0] = val[0:1]
        res = (val>>1)%2;
        res |= (val<<1)%4;
        break;
    case 1: // res[1:0] = val[1:0]
        res = val%4;
        break;
    default:
        res = 0;
        break;
}
val >>=2; // remove LSBs from val (prep first block)


reg_t temp;
for(int i=0; i<5; i++)
{
    res <<=6; // shift finished part to safety
    temp = (val & 0x3F) * mult_masks[group]; // create copies
    temp = temp & and_masks[group]; // select bits from copies
    res |= (temp % 255); // collapse selected bits together
    val >>=6; // prep next block
}

WRITE_RD(sext_xlen(res));
