#include "OpExecutors.h"

bool NOP_Executor::execute(CPU* cp)
{
	return cp->nop();
}