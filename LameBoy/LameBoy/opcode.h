#pragma once
#include "TypeDefs.h"
#include "OpExecutors.h"

class OpExecutor;

struct opcode {
	
	WORD code;
	const char* disassembly;
	BYTE operandLength;
	BYTE cyles;
	BYTE branchedCycles;
	const char* flagInfo;
	OpExecutor* executor;
};