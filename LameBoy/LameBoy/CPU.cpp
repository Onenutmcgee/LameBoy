#include "CPU.h"
#include "JumpTableLinker.h"

CPU::CPU(GamePak* cart)
{
	this->_cart = cart;
	this->_mem = new MemoryManager(cart);

	JumpTableLinker link;
	link.LinkOpcodesToExecutors(opcodes);

	Initialize();
}

CPU::~CPU()
{
	for(opcode op : opcodes)
	{
		if (op.executor)
			delete op.executor;
	}
	delete _mem;
}

void CPU::Initialize()
{
	reg.af = 0x01B0;
	reg.bc = 0x0013;
	reg.de = 0x00D8;
	reg.hl = 0x014D;
	reg.pc = 0x0100;
	reg.sp = 0xFFFE;
}

void CPU::Reset()
{
	_mem->Initialize();
	Initialize();
}

opcode CPU::ExecuteNextOpcode(BYTE* cycles)
{
	BYTE op = _mem->ReadByte(reg.pc);
	reg.pc++;

	opcode code = opcodes[op];
	
	// TODO: Remove this NULL check
	if (code.executor)
	{
		if (code.executor->execute(this))
		{
			*cycles = code.branchedCycles;
		}
		else
		{
			*cycles = code.cyles;
		}
	}
	else
	{
		exit(op);
	}
	
	return code;
}

opcode CPU::PeekNextOpcode()
{
	BYTE op = _mem->ReadByte(reg.pc);
	return opcodes[op];
}