reg_t num_iter = zext_xlen(insn.p_uimmL());
reg_t offset = zext_xlen(insn.p_uimmS() << 1);
bool loopNr = insn.p_loop();

reg_t start_addr = npc;  // next pc (pc+4)
reg_t end_addr = pc + offset;

p->hwLoops.set_end(loopNr, end_addr);
p->hwLoops.set_start(loopNr, start_addr);
p->hwLoops.set_count(loopNr, num_iter);
