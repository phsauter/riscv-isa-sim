reg_t offset = zext_xlen(insn.p_uimmL() << 1);
bool loopNr = insn.p_loop();

reg_t end_addr = pc + offset;

p->hwLoops.set_end(loopNr, end_addr);
