#include "CPU.h"

bool CPU::nop()
{
	return false;
}

bool CPU::push_reg(WORD val)
{
	BYTE upper = (BYTE)((val & 0xFF00) >> 8);
	BYTE lower = (BYTE)(val & 0x00FF);
	reg.sp--;
	_mem->WriteByte(reg.sp, upper);
	reg.sp--;
	_mem->WriteByte(reg.sp, lower);
	
	return false;
}

bool CPU::pop_reg(WORD* reg_addr)
{
	BYTE lower = _mem->ReadByte(reg.sp);
	reg.sp++;
	BYTE upper = _mem->ReadByte(reg.sp);
	reg.sp++;

	WORD val = upper;
	val = val << 8;
	val |= lower;

	*reg_addr = val;

	return false;
}

bool CPU::jp_addr(WORD address)
{
	WORD val = _mem->ReadWord(address);
	reg.pc = val;

	return true;
}

bool CPU::jp_val(WORD val)
{
	reg.pc = val;
	return true;
}

bool CPU::jp_flag_u16(BYTE flag, bool invert)
{
	WORD val = FetchNextImmediateWord();

	bool check = TestFlag(flag);

	if (invert)
		check = !check;

	if (check)
	{
		reg.pc = val;
		return true;
	}
	else
	{
		return false;
	}
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

bool CPU::call_u16()
{
	WORD addr = FetchNextImmediateWord();
	return call_addr(addr);
}

bool CPU::call_addr(WORD addr)
{
	push_reg(reg.pc);
	reg.pc = addr;
	return true;
}

bool CPU::call_flag_u16(BYTE flag, bool invert)
{
	WORD addr = FetchNextImmediateWord();

	bool check = TestFlag(flag);

	if (invert)
		check = !check;

	if (check)
	{
		return call_addr(addr);
	}
	else
	{
		return false;
	}
}

bool CPU::ret()
{
	pop_reg(&reg.pc);
	return true;
}

bool CPU::ret_flag(BYTE flag, bool invert)
{
	bool check = TestFlag(flag);

	if (invert)
		check = !check;

	if (check)
	{
		pop_reg(&reg.pc);
		return true;
	}
	else
	{
		return false;
	}
}

bool CPU::cpl_a()
{
	reg.a = ~reg.a;
	reg.f = 0x60;
	return false;
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

bool CPU::add_a_val(BYTE val)
{
	WORD a = reg.a;
	a += val;

	reg.f = 0x40;
	if ((reg.a & 0x0f) + (val & 0x0f) > 0x0f)
		SetFlag(FLAG_H);
	if (a > 0xFF)
		SetFlag(FLAG_C);
	reg.a = (BYTE)(a & 0xFF);

	if (reg.a == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::sub_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return sub_a_val(val);
}

bool CPU::add_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return add_a_val(val);
}

bool CPU::sub_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return sub_a_val(val);
}

bool CPU::add_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return add_a_val(val);
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

bool CPU::add_carry_a_val(BYTE val)
{
	BYTE oldA = reg.a;
	BYTE carry = TestFlag(FLAG_C) ? 1 : 0;

	int full_result = reg.a + val + carry;
	reg.a = static_cast<BYTE>(full_result);

	reg.f = 0x40;
	if (reg.a == 0)
		SetFlag(FLAG_Z);
	if (((oldA & 0x0f) + (val & 0x0f) + carry > 0x0f))
		SetFlag(FLAG_H);
	if (full_result > 0xFF)
		SetFlag(FLAG_C);
	return false;
}

bool CPU::sub_carry_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return sub_carry_a_val(val);
}

bool CPU::add_carry_a_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	return add_carry_a_val(val);
}

bool CPU::sub_carry_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return sub_carry_a_val(val);
}

bool CPU::add_carry_a_immediate_u8()
{
	BYTE val = FetchNextImmediateByte();
	return add_carry_a_val(val);
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

BYTE CPU::swap(BYTE reg_val)
{
	return (reg_val << 4) | (reg_val >> 4);
}

bool CPU::swap(BYTE* reg_addr)
{
	BYTE val = swap(*reg_addr);
	*reg_addr = val;
	reg.f ^= reg.f;
	if (val == 0)
		SetFlag(FLAG_Z);
	return false;
}

bool CPU::swap_addr(WORD address)
{
	BYTE val = swap(_mem->ReadByte(address));
	_mem->WriteByte(address, val);
	reg.f ^= reg.f;
	if (val == 0)
		SetFlag(FLAG_Z);

	return false;
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

bool CPU::add_hl(WORD val)
{
	WORD oldhl = reg.hl;
	int result = oldhl + val;
	reg.hl = (WORD)(result & 0xFFFF);

	reg.f &= 0x8f;

	if (((oldhl & 0xFFF) + (val & 0xFFF) & 0x1000) > 0)
		SetFlag(FLAG_H);

	if (result > 0xFFFF)
		SetFlag(FLAG_C);

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

// bit ops
bool CPU::bit_set(BYTE bit, BYTE* reg_addr)
{
	*reg_addr = (*reg_addr) | (1 << bit);
	return false;
}

bool CPU::bit_set(BYTE bit, WORD addr)
{
	BYTE val = _mem->ReadByte(addr);
	val |= (1 << bit);
	_mem->WriteByte(addr, val);
	return false;
}

bool CPU::bit_res(BYTE bit, BYTE* reg_addr)
{
	*reg_addr = (*reg_addr) & (~(1 << bit));
	return false;
}

bool CPU::bit_res(BYTE bit, WORD addr)
{
	BYTE val = _mem->ReadByte(addr);
	val &= (~(1 << bit));
	_mem->WriteByte(addr, val);
	return false;
}

bool CPU::bit_test(BYTE bit, BYTE val)
{
	bool test = ((val & (1 << bit)) == 0);

	ClearFlag(FLAG_N);
	SetFlag(FLAG_H);
	if (test)
		SetFlag(FLAG_Z);
	else
		ClearFlag(FLAG_Z);

	return false;
}

bool CPU::bit_test(BYTE bit, WORD addr)
{
	bit_test(bit, _mem->ReadByte(addr));
	return false;
}

bool CPU::rlc_reg(BYTE* reg_addr)
{
	BYTE val = *reg_addr;
	bool carry = (val & 0x80) != 0;

	reg.f = 0;
	*reg_addr = (val << 1) | (carry ? 0x1 : 0x0);

	if (carry)
		SetFlag(FLAG_C);
	if (*reg_addr == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::rlc_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	rlc_reg(&val);
	_mem->WriteByte(address, val);

	return false;
}

bool CPU::rrc_reg(BYTE* reg_addr)
{
	BYTE val = *reg_addr;
	bool carry = (val & 0x01) != 0;

	reg.f = 0;
	*reg_addr = (val >> 1) | (carry ? 0x80 : 0x0);

	if (carry)
		SetFlag(FLAG_C);
	if (*reg_addr == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::rrc_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	rrc_reg(&val);
	_mem->WriteByte(address, val);

	return false;
}

bool CPU::rl_reg(BYTE* reg_addr)
{
	BYTE val = *reg_addr;
	bool bit7 = (val & 0x80);

	*reg_addr = (val << 1) | (TestFlag(FLAG_C) ? 0x1 : 0x0);

	reg.f = 0;
	if (bit7)
		SetFlag(FLAG_C);
	if (*reg_addr == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::rl_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	rl_reg(&val);
	_mem->WriteByte(address, val);

	return false;
}

bool CPU::rr_reg(BYTE* reg_addr)
{
	BYTE val = *reg_addr;
	bool bit0 = (val & 0x01);

	*reg_addr = (val >> 1) | (TestFlag(FLAG_C) ? 0x8 : 0x0);

	reg.f = 0;
	if (bit0)
		SetFlag(FLAG_C);
	if (*reg_addr == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::rr_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	rr_reg(&val);
	_mem->WriteByte(address, val);

	return false;
}

bool CPU::sla_reg(BYTE* reg_addr)
{
	BYTE val = *reg_addr;
	bool bit7 = (val & 0x80);

	*reg_addr = (val << 1) ;

	reg.f = 0;
	if (bit7)
		SetFlag(FLAG_C);
	if (*reg_addr == 0)
		SetFlag(FLAG_Z);
	
	return false;
}

bool CPU::sla_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	sla_reg(&val);
	_mem->WriteByte(address, val);

	return false;
}

bool CPU::sra_reg(BYTE* reg_addr)
{
	BYTE val = *reg_addr;
	bool bit0 = (val & 0x01);
	BYTE bit7 = (val & 0x80);

	*reg_addr = ((val >> 1) | bit7);

	reg.f = 0;
	if (bit0)
		SetFlag(FLAG_C);
	if (*reg_addr == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::sra_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	sra_reg(&val);
	_mem->WriteByte(address, val);

	return false;
}

bool CPU::srl_reg(BYTE* reg_addr)
{
	BYTE val = *reg_addr;
	bool bit0 = (val & 0x01);

	*reg_addr = (val >> 1);

	reg.f = 0;
	if (bit0)
		SetFlag(FLAG_C);
	if (*reg_addr == 0)
		SetFlag(FLAG_Z);

	return false;
}

bool CPU::srl_addr(WORD address)
{
	BYTE val = _mem->ReadByte(address);
	srl_reg(&val);
	_mem->WriteByte(address, val);

	return false;
}