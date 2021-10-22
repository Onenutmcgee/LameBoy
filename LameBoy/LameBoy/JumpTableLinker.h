#pragma once

#include "OpExecutors.h"
#include "opcode.h"

class JumpTableLinker
{
public:
	JumpTableLinker() {};

	void LinkOpcodesToExecutors(opcode opcodes[])
	{
		opcodes[0x00].executor = new NOP_Executor();
	}
};