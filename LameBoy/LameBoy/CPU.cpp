#include "CPU.h"
#include "OpcodeNotImplementedException.h"

CPU::CPU(GamePak* cart)
{
	this->_cart = cart;
	this->_mem = new MemoryManager(cart);

	Initialize();
}

CPU::~CPU()
{
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

OPC::opcode CPU::ExecuteNextOpcode(BYTE* cycles)
{
	BYTE op = _mem->ReadByte(reg.pc);
	reg.pc++;

	OPC::opcode code = OPC::opcodes[op];

	if (code.code == 0xCB)
	{
		op = _mem->ReadByte(reg.pc);
		reg.pc++;
		code = OPC::ext_opcodes[op];
	}
	
	// TODO: Remove this NULL check
	if (code.execute)
	{
		if (code.execute(this))
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
		throw OpcodeNotImplException(code);
	}
	
	return code;
}

BYTE CPU::FetchNextImmediateByte()
{
	BYTE val = _mem->ReadByte(reg.pc);
	reg.pc++;
	return val;
}

WORD CPU::FetchNextImmediateWord()
{
	WORD val = _mem->ReadWord(reg.pc);
	reg.pc += 2;
	return val;
}

OPC::opcode CPU::PeekNextOpcode()
{
	BYTE op = _mem->ReadByte(reg.pc);

	if (op == 0xCB)
	{
		op = _mem->ReadByte(reg.pc + 1);
		return OPC::ext_opcodes[op];
	}
	return OPC::opcodes[op];
}


void CPU::SetFlag(BYTE flag)
{
	reg.f |= (1 << flag);
}

void CPU::ClearFlag(BYTE flag)
{
	BYTE t = (1 << flag);
	reg.f &= ~t;
}

bool CPU::TestFlag(BYTE flag)
{
	return reg.f & (1 << flag);
}

bool CPU::set_interrupts_enabled(bool val)
{
	interrupts_enabled = val;
	return false;
}