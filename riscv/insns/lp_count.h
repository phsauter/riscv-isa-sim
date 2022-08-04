reg_t num_iter = zext_xlen(RS1);
bool loopNr = insn.p_loop();

p->hwLoops.set_count(loopNr, num_iter);
