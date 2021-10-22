#include "OpExecutors.h"
#include "CPU.h"


bool NOP_Executor::execute(CPU* cp)
{
	return cp->nop();
}

bool JP_u16_Executor::execute(CPU* cp)
{
	return cp->jp_u16();
}

bool XOR_a_Executor::execute(CPU* cp)
{
	return cp->xor_n(cp->reg.a);
}

bool LD_hl_u16_Executor::execute(CPU* cp)
{
	return cp->ld_hl_u16();
}