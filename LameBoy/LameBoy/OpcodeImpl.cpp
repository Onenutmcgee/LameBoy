#include "CPU.h"

bool CPU::nop()
{
	return false;
}

bool CPU::jp_u16()
{
	WORD address = _mem->ReadWord(reg.pc);
	reg.pc = address;

	return false;
}

bool CPU::xor_n(BYTE comp)
{
	reg.a ^= comp;

	reg.f = 0;
	if (reg.a == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::ld_hl_u16()
{
	WORD val = _mem->ReadWord(reg.pc);
	reg.pc += 2;

	reg.hl = val;

	return false;
}