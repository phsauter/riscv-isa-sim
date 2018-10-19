// See LICENSE for license details.

#ifndef _RISCV_UST_TRACER_H
#define _RISCV_UST_TRACER_H

#include "processor.h"

void ust_open(const char *filename);
void ust_start(void);
void ust_step(void);
void ust_close(void);
void ust_set_addr(reg_t addr);
void ust_set_insn(uint64_t insn);
void ust_set_priv(uint8_t prv);
void ust_set_exception(reg_t cause);
void ust_set_tval(reg_t tval);
void ust_set_interrupt(uint8_t interrupt);

#endif
