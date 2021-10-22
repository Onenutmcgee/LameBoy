#pragma once
#include "TypeDefs.h"
#include "OpExecutors.h"

class CPU;

namespace OPC
{
	bool exe_nop(CPU* cp);

	struct opcode {

		WORD code;
		const char* disassembly;
		BYTE operandLength;
		BYTE cyles;
		BYTE branchedCycles;
		const char* flagInfo;
		bool (*execute)(CPU*);
	};

	extern struct opcode opcodes[];

	
}