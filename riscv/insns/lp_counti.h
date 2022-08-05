reg_t num_iter = zext_xlen(insn.p_uimmL());
bool loopNr = insn.p_loop();

p->hwLoops.set_count(loopNr, num_iter);
