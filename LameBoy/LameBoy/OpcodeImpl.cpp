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

bool CPU::xor_a_val(BYTE comp)
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
	return xor_a_val(val);
}

bool CPU::xor_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return xor_a_val(val);
}

bool CPU::or_a_val(BYTE val)
{
	reg.a |= val;

	reg.f = 0;
	if (reg.a == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::or_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return or_a_val(val);
}

bool CPU::or_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return or_a_val(val);
}

bool CPU::and_a_val(BYTE val)
{
	reg.a &= val;

	reg.f = 0x20;
	if (reg.a == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::and_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return and_a_val(val);
}

bool CPU::and_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return and_a_val(val);
}

bool CPU::sub_a_val(BYTE val)
{
	BYTE oldA = reg.a;
	reg.a -= val;

	reg.f = 0x40;
	if (reg.a == 0)
		SetFlag(FLAG_Z);
	if ((oldA & 0xf) < (val & 0xf))
		SetFlag(FLAG_H);
	if (oldA < val)
		SetFlag(FLAG_C);
	return false;
}

bool CPU::sub_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return sub_a_val(val);
}

bool CPU::sub_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return sub_a_val(val);
}

bool CPU::sub_carry_a_val(BYTE val)
{
	BYTE oldA = reg.a;
	BYTE carry = TestFlag(FLAG_C) ? 1 : 0;

	int full_result = reg.a - val - carry;
	reg.a = static_cast<BYTE>(full_result);

	reg.f = 0x40;
	if (reg.a == 0)
		SetFlag(FLAG_Z);
	if (((oldA & 0xf) < (val & 0xf) + carry))
		SetFlag(FLAG_H);
	if (full_result < 0)
		SetFlag(FLAG_C);
	return false;
}

bool CPU::sub_carry_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return sub_carry_a_val(val);
}

bool CPU::sub_carry_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return sub_carry_a_val(val);
}

bool CPU::cp_a_val(BYTE val)
{
	reg.f = 0x40;
	if (reg.a == val)
		SetFlag(FLAG_Z);
	if ((reg.a & 0xf) < (val & 0xf))
		SetFlag(FLAG_H);
	if (reg.a < val)
		SetFlag(FLAG_C);
	return false;
}

bool CPU::cp_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return cp_a_val(val);
}

bool CPU::cp_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return cp_a_val(val);
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

bool CPU::ld_a_addr_immediate_u16()
{
	WORD address = FetchNextImmediateWord();
	return ld_a_addr(address);
}

bool CPU::ld_a_addr_offset_u8(WORD offset)
{
	BYTE val = FetchNextImmediateByte();
	return ld_a_addr(offset + val);
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

bool CPU::ld_offset_u8_val(WORD offset, BYTE val)
{
	BYTE addOffset = FetchNextImmediateByte();
	return ld_addr_val(offset + addOffset, val);
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