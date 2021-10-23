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

bool CPU::ld_immediate_u16_dest(WORD* dest)
{
	WORD val = _mem->ReadWord(reg.pc);
	reg.pc += 2;

	*dest = val;

	return false;
}

bool CPU::ld_immediate_u8_dest(BYTE* dest)
{
	BYTE val = _mem->ReadByte(reg.pc);
	reg.pc++;

	*dest = val;
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
	reg.b = val;
	return false;
}

bool CPU::ld_b_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_b_val(val);
}

bool CPU::ld_c_val(BYTE val)
{
	reg.c = val;
	return false;
}

bool CPU::ld_c_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_c_val(val);
}

bool CPU::ld_d_val(BYTE val)
{
	reg.d = val;
	return false;
}

bool CPU::ld_d_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_d_val(val);
}

bool CPU::ld_e_val(BYTE val)
{
	reg.e = val;
	return false;
}

bool CPU::ld_e_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_e_val(val);
}

bool CPU::ld_h_val(BYTE val)
{
	reg.h = val;
	return false;
}

bool CPU::ld_h_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_h_val(val);
}

bool CPU::ld_l_val(BYTE val)
{
	reg.l = val;
	return false;
}

bool CPU::ld_l_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return ld_l_val(val);
}
