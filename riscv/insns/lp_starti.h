reg_t offset = insn.p_uimmL() << 1;
bool loopNr = insn.p_loop();

reg_t start_addr = pc + offset;

p->hwLoops.set_start(loopNr, start_addr);
