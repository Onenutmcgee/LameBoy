#include "CPU.h"

bool CPU::nop()
{
	return false;
}

bool CPU::jp_addr(WORD address)
{
	WORD val = _mem->ReadWord(address);
	reg.pc = val;

	return true;
}

bool CPU::jr_i8()
{
	SIGNED_BYTE val = _mem->ReadSignedByte(reg.pc);
	reg.pc++;

	reg.pc += val;

	return true;
}

bool CPU::jr_flag_i8(BYTE flag, bool invert)
{
	SIGNED_BYTE val = _mem->ReadSignedByte(reg.pc);
	reg.pc++;

	bool check = TestFlag(flag);

	if (invert)
		check = !check;

	if (check)
	{
		reg.pc += val;
		return true;
	}
	else
	{
		return false;
	}
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
	WORD val = FetchNextImmediateWord();

	*dest = val;

	return false;
}

bool CPU::ld_immediate_u8_dest(BYTE* dest)
{
	BYTE val = FetchNextImmediateByte();

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

bool CPU::ldd_addr_hl(BYTE val)
{
	_mem->WriteByte(reg.hl, val);
	reg.hl--;
	return false;
}

bool CPU::ldi_addr_hl(BYTE val)
{
	_mem->WriteByte(reg.hl, val);
	reg.hl++;
	return false;
}

bool CPU::ld_addr_val(WORD address, BYTE val)
{
	_mem->WriteByte(address, val);
	return false;
}

bool CPU::ld_addr_immediate_u8(WORD address)
{
	BYTE val = FetchNextImmediateByte();
	_mem->WriteByte(address, val);
	return false;
}

bool CPU::ld_immediate_u16_addr_val(BYTE val)
{
	WORD address = FetchNextImmediateWord();
	return ld_addr_val(address, val);
}

bool CPU::dec_reg(BYTE* regAddr)
{
	(*regAddr)--;

	if (*regAddr == 0)
		SetFlag(FLAG_Z);
	else
		ClearFlag(FLAG_Z);
	SetFlag(FLAG_N);

	// For BYTEs, half carry flag only set when moving from 0xX0 and down ot 0x(x-1)F
	if ((*regAddr & 0x0F) == 0x0F)
		SetFlag(FLAG_H);
	else
		ClearFlag(FLAG_H);

	return false;
}

bool CPU::inc_reg(BYTE* regAddr)
{
	(*regAddr)++;

	if (*regAddr == 0)
		SetFlag(FLAG_Z);
	else
		ClearFlag(FLAG_Z);
	ClearFlag(FLAG_N);

	// For BYTEs, half carry flag only set when moving from 0xXF and up
	if ((*regAddr & 0x0F) == 0x00)
		SetFlag(FLAG_H);
	else
		ClearFlag(FLAG_H);

	return false;
}

bool CPU::dec_reg(WORD* regAddr)
{
	(*regAddr)--;
	return false;
}

bool CPU::inc_reg(WORD* regAddr)
{
	(*regAddr)++;
	return false;
}