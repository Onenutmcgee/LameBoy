#include "CPU.h"

bool CPU::nop()
{
	return false;
}

bool CPU::jp_addr(WORD address)
{
	WORD val = _mem->ReadWord(address);
	reg.pc = val;

	return false;
}

bool CPU::xor_a_n(BYTE comp)
{
	reg.a ^= comp;

	reg.f = 0;
	if (reg.a == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::xor_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return xor_a_n(val);
}

bool CPU::ld_hl_u16()
{
	WORD val = _mem->ReadWord(reg.pc);
	reg.pc += 2;

	reg.hl = val;

	return false;
}

bool CPU::ld_a_val(BYTE val)
{
	reg.a = val;

	return false;
}

bool CPU::ld_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_a_val(val);
}

bool CPU::ld_b_val(BYTE val)
{
	reg.a = val;

	return false;
}

bool CPU::ld_b_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_a_val(val);
}

