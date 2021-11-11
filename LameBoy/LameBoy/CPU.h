#pragma once
#include "MemoryManager.h"
#include "GamePak.h"
#include "Registers.h"
#include "opcode.h"

#define FLAG_Z 7
#define FLAG_N 6
#define FLAG_H 5
#define FLAG_C 4

class CPU
{
public:
	CPU(GamePak* cart, MemoryManager* mem);
	~CPU();

	Registers reg;

	void Initialize();
	void Reset();
	OPC::opcode ExecuteNextOpcode(BYTE*);
	OPC::opcode PeekNextOpcode();
	
	void HandleInterrupts();

	bool nop();
	bool daa();
	bool scf();
	bool ccf();
	bool set_interrupts_enabled(bool);
	bool push_reg(WORD reg);
	bool pop_reg(WORD* reg);

	// jumps
	bool jp_addr(WORD);
	bool jp_val(WORD);
	bool jp_flag_u16(BYTE flag, bool invert);
	bool jr_i8();
	bool jr_flag_i8(BYTE flag, bool invert);
	bool call_u16();
	bool call_flag_u16(BYTE flag, bool invert);
	bool call_addr(WORD addr);
	bool ret();
	bool ret_flag(BYTE flag, bool invert);

	// byte ALU
	bool cpl_a();
	bool xor_a_val(BYTE val);
	bool xor_a_addr(WORD);
	bool xor_a_immediate_u8();
	bool or_a_val(BYTE val);
	bool or_a_addr(WORD address);
	bool or_a_immediate_u8();
	bool and_a_val(BYTE val);
	bool and_a_addr(WORD address);
	bool and_a_immediate_u8();
	bool dec_reg(BYTE*);
	bool inc_reg(BYTE*);
	bool dec_addr(WORD);
	bool inc_addr(WORD);
	bool sub_a_val(BYTE val);
	bool sub_a_addr(WORD address);
	bool sub_a_immediate_u8();
	bool sub_carry_a_val(BYTE val);
	bool sub_carry_a_addr(WORD val);
	bool sub_carry_a_immediate_u8();
	
	bool add_a_val(BYTE val);
	bool add_a_addr(WORD address);
	bool add_a_immediate_u8();
	bool add_carry_a_val(BYTE val);
	bool add_carry_a_addr(WORD val);
	bool add_carry_a_immediate_u8();
	
	bool cp_a_val(BYTE val);
	bool cp_a_addr(WORD address);
	bool cp_a_immediate_u8();
	bool swap(BYTE* reg_addr);
	bool swap_addr(WORD address);

	// word ALU
	bool dec_reg(WORD*);
	bool inc_reg(WORD*);
	bool add_hl(WORD val);
	bool add_sp_i8();

	// 16 bit loads
	bool ld_immediate_u16_dest(WORD*);
	bool ld_sp_into_immediate_u16_addr();
	bool ld_hl_into_sp();
	bool ld_sp_with_immidiate_i8_into_hl();

	// 8 bit loads
	bool ld_immediate_u8_dest(BYTE*);

	// TODO: replace the individual register writes with more generic calls
	/*
	bool ld_reg_val(BYTE* dest, BYTE val);
	bool ld_reg_addr(BYTE* dest, WORD address);
	*/
	bool ld_a_val(BYTE);
	bool ld_a_addr(WORD);
	bool ld_a_addr_immediate_u16();
	bool ld_a_addr_offset_u8(WORD offset);
	bool ld_b_val(BYTE);
	bool ld_b_addr(WORD);
	bool ld_c_val(BYTE);
	bool ld_c_addr(WORD);
	bool ld_d_val(BYTE);
	bool ld_d_addr(WORD);
	bool ld_e_val(BYTE);
	bool ld_e_addr(WORD);
	bool ld_h_val(BYTE);
	bool ld_h_addr(WORD);
	bool ld_l_val(BYTE);
	bool ld_l_addr(WORD);

	// 8 bit writes
	bool ldd_addr_hl(BYTE);
	bool ldi_addr_hl(BYTE);
	bool ld_addr_val(WORD address, BYTE val);
	bool ld_addr_immediate_u8(WORD address);
	bool ld_immediate_u16_addr_val(BYTE val);
	bool ld_offset_u8_val(WORD offset, BYTE val);

	// bit set, res, and test
	bool bit_set(BYTE bit, BYTE* reg_addr);
	bool bit_set(BYTE bit, WORD addr);
	bool bit_res(BYTE bit, BYTE* reg_addr);
	bool bit_res(BYTE bit, WORD addr);
	bool bit_test(BYTE bit, BYTE val);
	bool bit_test(BYTE bit, WORD addr);

	// bit rotates
	bool rlc_reg(BYTE* reg_addr);
	bool rlc_addr(WORD addr);
	bool rrc_reg(BYTE* reg_addr);
	bool rrc_addr(WORD addr);
	bool rl_reg(BYTE* reg_addr);
	bool rl_addr(WORD addr);
	bool rr_reg(BYTE* reg_addr);
	bool rr_addr(WORD addr);
	bool sla_reg(BYTE* reg_addr);
	bool sla_addr(WORD addr);
	bool sra_reg(BYTE* reg_addr);
	bool sra_addr(WORD addr);
	bool srl_reg(BYTE* reg_addr);
	bool srl_addr(WORD addr);

private:
	void SetFlag(BYTE);
	void ClearFlag(BYTE);
	bool TestFlag(BYTE);
	BYTE swap(BYTE);

	void ServiceInterrupt(BYTE);
	BYTE FetchNextImmediateByte();
	WORD FetchNextImmediateWord();


	MemoryManager* _mem;
	GamePak* _cart;
	bool interrupts_enabled = true;
	
};

