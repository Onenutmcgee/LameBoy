#pragma once
#include "TypeDefs.h"

class CPU;

namespace OPC
{
	bool exe_nop(CPU* cp);
	bool exe_di(CPU* cp);
	bool exe_ei(CPU* cp);

	// jumps
	bool exe_jp_addr_pc(CPU* cp);

	bool exe_jr_i8(CPU* cp);
	bool exe_jr_nz_i8(CPU* cp);
	bool exe_jr_z_i8(CPU* cp);
	bool exe_jr_nc_i8(CPU* cp);
	bool exe_jr_c_i8(CPU* cp);

	// 8-bit loads
	bool exe_ld_a_u8(CPU* cp);
	bool exe_ld_b_u8(CPU* cp);
	bool exe_ld_c_u8(CPU* cp);
	bool exe_ld_d_u8(CPU* cp);
	bool exe_ld_e_u8(CPU* cp);
	bool exe_ld_h_u8(CPU* cp);
	bool exe_ld_l_u8(CPU* cp);

	bool exe_ld_a_b(CPU* cp);
	bool exe_ld_a_c(CPU* cp);
	bool exe_ld_a_d(CPU* cp);
	bool exe_ld_a_e(CPU* cp);
	bool exe_ld_a_h(CPU* cp);
	bool exe_ld_a_l(CPU* cp);
	bool exe_ld_a_addr_hl(CPU* cp);
	bool exe_ld_a_addr_hl_inc(CPU* cp);
	bool exe_ld_a_addr_hl_dec(CPU* cp);
	bool exe_ld_a_addr_bc(CPU* cp);
	bool exe_ld_a_addr_de(CPU* cp);
	bool exe_ld_a_addr_ff00_u8(CPU* cp);
	bool exe_ld_a_addr_ff00_c(CPU* cp);
	bool exe_ld_a_addr_u16(CPU* cp);

	bool exe_ld_b_a(CPU* cp);
	bool exe_ld_b_c(CPU* cp);
	bool exe_ld_b_d(CPU* cp);
	bool exe_ld_b_e(CPU* cp);
	bool exe_ld_b_h(CPU* cp);
	bool exe_ld_b_l(CPU* cp);
	bool exe_ld_b_addr_hl(CPU* cp);

	bool exe_ld_c_a(CPU* cp);
	bool exe_ld_c_b(CPU* cp);
	bool exe_ld_c_d(CPU* cp);
	bool exe_ld_c_e(CPU* cp);
	bool exe_ld_c_h(CPU* cp);
	bool exe_ld_c_l(CPU* cp);
	bool exe_ld_c_addr_hl(CPU* cp);

	bool exe_ld_d_a(CPU* cp);
	bool exe_ld_d_b(CPU* cp);
	bool exe_ld_d_c(CPU* cp);
	bool exe_ld_d_e(CPU* cp);
	bool exe_ld_d_h(CPU* cp);
	bool exe_ld_d_l(CPU* cp);
	bool exe_ld_d_addr_hl(CPU* cp);

	bool exe_ld_e_a(CPU* cp);
	bool exe_ld_e_b(CPU* cp);
	bool exe_ld_e_c(CPU* cp);
	bool exe_ld_e_d(CPU* cp);
	bool exe_ld_e_h(CPU* cp);
	bool exe_ld_e_l(CPU* cp);
	bool exe_ld_e_addr_hl(CPU* cp);

	bool exe_ld_h_a(CPU* cp);
	bool exe_ld_h_b(CPU* cp);
	bool exe_ld_h_c(CPU* cp);
	bool exe_ld_h_d(CPU* cp);
	bool exe_ld_h_e(CPU* cp);
	bool exe_ld_h_l(CPU* cp);
	bool exe_ld_h_addr_hl(CPU* cp);

	bool exe_ld_l_a(CPU* cp);
	bool exe_ld_l_b(CPU* cp);
	bool exe_ld_l_c(CPU* cp);
	bool exe_ld_l_d(CPU* cp);
	bool exe_ld_l_e(CPU* cp);
	bool exe_ld_l_h(CPU* cp);
	bool exe_ld_l_addr_hl(CPU* cp);

	// 8-bit writes
	bool exe_ldd_hl_a(CPU* cp);
	bool exe_ldi_hl_a(CPU* cp);

	bool exe_ld_hl_a(CPU* cp);
	bool exe_ld_hl_b(CPU* cp);
	bool exe_ld_hl_c(CPU* cp);
	bool exe_ld_hl_d(CPU* cp);
	bool exe_ld_hl_e(CPU* cp);
	bool exe_ld_hl_h(CPU* cp);
	bool exe_ld_hl_l(CPU* cp);

	bool exe_ld_immediate_u16_a(CPU* cp);
	bool exe_ld_bc_a(CPU* cp);
	bool exe_ld_de_a(CPU* cp);

	bool exe_ld_addr_hl_u8(CPU* cp);
	bool exe_ld_ff00_immediate_u8_a(CPU* cp);
	bool exe_ld_ff00_c_a(CPU* cp);

	// 16-bit loads
	bool exe_ld_hl_u16(CPU* cp);
	bool exe_ld_bc_u16(CPU* cp);
	bool exe_ld_de_u16(CPU* cp);
	bool exe_ld_sp_u16(CPU* cp);

	// ALU
	// XOR
	bool exe_xor_a_a(CPU* cp);
	bool exe_xor_a_b(CPU* cp);
	bool exe_xor_a_c(CPU* cp);
	bool exe_xor_a_d(CPU* cp);
	bool exe_xor_a_e(CPU* cp);
	bool exe_xor_a_h(CPU* cp);
	bool exe_xor_a_l(CPU* cp);
	bool exe_xor_a_addr_hl(CPU* cp);

	// AND
	bool exe_and_a_a(CPU* cp);
	bool exe_and_a_b(CPU* cp);
	bool exe_and_a_c(CPU* cp);
	bool exe_and_a_d(CPU* cp);
	bool exe_and_a_e(CPU* cp);
	bool exe_and_a_h(CPU* cp);
	bool exe_and_a_l(CPU* cp);
	bool exe_and_a_addr_hl(CPU* cp);

	// or
	bool exe_or_a_a(CPU* cp);
	bool exe_or_a_b(CPU* cp);
	bool exe_or_a_c(CPU* cp);
	bool exe_or_a_d(CPU* cp);
	bool exe_or_a_e(CPU* cp);
	bool exe_or_a_h(CPU* cp);
	bool exe_or_a_l(CPU* cp);
	bool exe_or_a_addr_hl(CPU* cp);

	// INC
	bool exe_inc_a(CPU* cp);
	bool exe_inc_b(CPU* cp);
	bool exe_inc_c(CPU* cp);
	bool exe_inc_d(CPU* cp);
	bool exe_inc_e(CPU* cp);
	bool exe_inc_h(CPU* cp);
	bool exe_inc_l(CPU* cp);
	bool exe_inc_bc(CPU* cp);
	bool exe_inc_de(CPU* cp);
	bool exe_inc_hl(CPU* cp);
	bool exe_inc_sp(CPU* cp);

	// DEC
	bool exe_dec_a(CPU* cp);
	bool exe_dec_b(CPU* cp);
	bool exe_dec_c(CPU* cp);
	bool exe_dec_d(CPU* cp);
	bool exe_dec_e(CPU* cp);
	bool exe_dec_h(CPU* cp);
	bool exe_dec_l(CPU* cp);
	bool exe_dec_bc(CPU* cp);
	bool exe_dec_de(CPU* cp);
	bool exe_dec_hl(CPU* cp);
	bool exe_dec_sp(CPU* cp);

	struct opcode {

		WORD code;
		const char* disassembly;
		BYTE operandLength;
		BYTE cyles;
		BYTE branchedCycles;
		const char* flagInfo;
		bool (*execute)(CPU*);
	};

	extern struct opcode opcodes[];

	
}