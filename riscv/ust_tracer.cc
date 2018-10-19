// See LICENSE for license details.

#include "ust_tracer.h"
#include "trap.h"

#include <cstdio>

static reg_t s_addr = 0;
static uint64_t s_insn = 0;
static uint8_t s_prv = 0;
static uint8_t s_ex = 0;
static reg_t s_ex_cause = 0;
static reg_t s_tval = 0;
static uint8_t s_interrupt = 0;
static FILE* s_trace = NULL;
static bool has_output_header = false;

void ust_open(const char *filename)
{
  if(!filename)
    return;
  s_trace = fopen(filename, "w");
  if (!s_trace)
    fprintf(stderr, "Failed to open ust trace file %s: %s",
            filename, strerror(errno));
}

void ust_step(void)
{
  if (!s_trace)
    return;

  if (has_output_header) {
    fprintf(s_trace, "1,%lx,%lx,%x,%x,%lx,%lx,%x\n",
	    s_addr, s_insn, s_prv, s_ex, s_ex_cause, s_tval, s_interrupt);
  } else {
    fprintf(s_trace, "VALID,ADDRESS,INSN,PRIVILEGE,EXCEPTION,ECAUSE,TVAL,INTERRUPT\n");
    has_output_header = true;
  }

  s_ex = 0;
}

void ust_close(void)
{
  if (s_trace)
    fclose(s_trace);
  s_trace = NULL;
}

void ust_set_addr(reg_t addr) {
  s_addr = addr;
}

void ust_set_insn(uint64_t insn) {
  s_insn = insn;
}

void ust_set_priv(uint8_t prv) {
  s_prv = prv;
}

void ust_set_exception(reg_t cause) {
  s_ex = 1;
  s_ex_cause = cause;
}

void ust_set_tval(reg_t tval) {
  s_tval = tval;
}

void ust_set_interrupt(uint8_t interrupt) {
  s_interrupt = interrupt;
}
