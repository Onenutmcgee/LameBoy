#pragma once
#include "TypeDefs.h"

class CPU;

namespace OPC
{
	bool exe_nop(CPU* cp);

	// jumps
	bool exe_jp_addr_pc(CPU* cp);

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