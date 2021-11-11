#include "CPU.h"
#include "OpcodeNotImplementedException.h"

CPU::CPU(GamePak* cart, MemoryManager* mem)
{
	this->_cart = cart;
	this->_mem = mem;

	Initialize();
}

CPU::~CPU()
{
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

void CPU::HandleInterrupts()
{
	if (interrupts_enabled)
	{
		BYTE interruptRegister = _mem->ReadByte(0xFF0F);
		BYTE ieRegister = _mem->ReadByte(0xFFFF) & 0x1F;

		if (interruptRegister > 0)
		{ // there are interrupt(s)
			// we only care if the interrupts are enabled
			interruptRegister &= ieRegister;

			if (interruptRegister > 0)
			{ // we have an enabled interrupt
				BYTE interruptBit = 0;
				bool found = false;

				while (!found && interruptBit < 5)
				{
					found = (interruptRegister & (1 << interruptBit));
					if (!found)
						interruptBit++;
				}

				if (found)
					ServiceInterrupt(interruptBit);
			}
		}
	}
}

void CPU::ServiceInterrupt(BYTE id)
{
	bit_res(id, (WORD)0xFF0F);
	interrupts_enabled = false;

	push_reg(reg.pc);

	switch (id)
	{
	case INTERRUPT_VBLANK:
		reg.pc = 0x40;
		break;
	case INTERRUPT_LCD:
		reg.pc = 0x48;
		break;
	case INTERRUPT_TIMER:
		reg.pc = 0x50;
		break;
	case INTERRUPT_JOYPAD:
		reg.pc = 0x60;
		break;
	}
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