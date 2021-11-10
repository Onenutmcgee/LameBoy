#pragma once
#include "TypeDefs.h"

class CPU;

namespace OPC
{
	bool exe_nop(CPU* cp);
	bool exe_di(CPU* cp);
	bool exe_ei(CPU* cp);

	bool exe_push_bc(CPU* cp);
	bool exe_pop_bc(CPU* cp);
	bool exe_push_de(CPU* cp);
	bool exe_pop_de(CPU* cp);
	bool exe_push_hl(CPU* cp);
	bool exe_pop_hl(CPU* cp);
	bool exe_push_af(CPU* cp);
	bool exe_pop_af(CPU* cp);

	// jumps
	bool exe_jp_addr_pc(CPU* cp);
	bool exe_jp_hl(CPU* cp);

	bool exe_jr_i8(CPU* cp);
	bool exe_jr_nz_i8(CPU* cp);
	bool exe_jr_z_i8(CPU* cp);
	bool exe_jr_nc_i8(CPU* cp);
	bool exe_jr_c_i8(CPU* cp);

	bool exe_call_u16(CPU*);
	bool exe_call_nz_u16(CPU*);
	bool exe_call_z_u16(CPU*);
	bool exe_call_nc_u16(CPU*);
	bool exe_call_c_u16(CPU*);

	bool exe_rst_00(CPU*);
	bool exe_rst_08(CPU*);
	bool exe_rst_10(CPU*);
	bool exe_rst_18(CPU*);
	bool exe_rst_20(CPU*);
	bool exe_rst_28(CPU*);
	bool exe_rst_30(CPU*);
	bool exe_rst_38(CPU*);

	bool exe_ret(CPU*);
	bool exe_reti(CPU*);
	bool exe_ret_nz(CPU*);
	bool exe_ret_z(CPU*);
	bool exe_ret_nc(CPU*);
	bool exe_ret_c(CPU*);

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
	bool exe_cpl_a(CPU* cp);
	 
	// ADD
	bool exe_add_a_a(CPU* cp);
	bool exe_add_a_b(CPU* cp);
	bool exe_add_a_c(CPU* cp);
	bool exe_add_a_d(CPU* cp);
	bool exe_add_a_e(CPU* cp);
	bool exe_add_a_h(CPU* cp);
	bool exe_add_a_l(CPU* cp);
	bool exe_add_a_addr_hl(CPU* cp);
	bool exe_add_a_u8(CPU* cp);
	bool exe_add_hl_bc(CPU* cp);
	bool exe_add_hl_de(CPU* cp);
	bool exe_add_hl_hl(CPU* cp);
	bool exe_add_hl_sp(CPU* cp);

	// ADC
	bool exe_adc_a_a(CPU* cp);
	bool exe_adc_a_b(CPU* cp);
	bool exe_adc_a_c(CPU* cp);
	bool exe_adc_a_d(CPU* cp);
	bool exe_adc_a_e(CPU* cp);
	bool exe_adc_a_h(CPU* cp);
	bool exe_adc_a_l(CPU* cp);
	bool exe_adc_a_addr_hl(CPU* cp);
	bool exe_adc_a_u8(CPU* cp);

	// SUB
	bool exe_sub_a_a(CPU* cp);
	bool exe_sub_a_b(CPU* cp);
	bool exe_sub_a_c(CPU* cp);
	bool exe_sub_a_d(CPU* cp);
	bool exe_sub_a_e(CPU* cp);
	bool exe_sub_a_h(CPU* cp);
	bool exe_sub_a_l(CPU* cp);
	bool exe_sub_a_addr_hl(CPU* cp);
	bool exe_sub_a_u8(CPU* cp);

	// SBC
	bool exe_sbc_a_a(CPU* cp);
	bool exe_sbc_a_b(CPU* cp);
	bool exe_sbc_a_c(CPU* cp);
	bool exe_sbc_a_d(CPU* cp);
	bool exe_sbc_a_e(CPU* cp);
	bool exe_sbc_a_h(CPU* cp);
	bool exe_sbc_a_l(CPU* cp);
	bool exe_sbc_a_addr_hl(CPU* cp);
	bool exe_sbc_a_u8(CPU* cp);

	// XOR
	bool exe_xor_a_a(CPU* cp);
	bool exe_xor_a_b(CPU* cp);
	bool exe_xor_a_c(CPU* cp);
	bool exe_xor_a_d(CPU* cp);
	bool exe_xor_a_e(CPU* cp);
	bool exe_xor_a_h(CPU* cp);
	bool exe_xor_a_l(CPU* cp);
	bool exe_xor_a_addr_hl(CPU* cp);
	bool exe_xor_a_u8(CPU* cp);

	// AND
	bool exe_and_a_a(CPU* cp);
	bool exe_and_a_b(CPU* cp);
	bool exe_and_a_c(CPU* cp);
	bool exe_and_a_d(CPU* cp);
	bool exe_and_a_e(CPU* cp);
	bool exe_and_a_h(CPU* cp);
	bool exe_and_a_l(CPU* cp);
	bool exe_and_a_addr_hl(CPU* cp);
	bool exe_and_a_u8(CPU* cp);

	// or
	bool exe_or_a_a(CPU* cp);
	bool exe_or_a_b(CPU* cp);
	bool exe_or_a_c(CPU* cp);
	bool exe_or_a_d(CPU* cp);
	bool exe_or_a_e(CPU* cp);
	bool exe_or_a_h(CPU* cp);
	bool exe_or_a_l(CPU* cp);
	bool exe_or_a_addr_hl(CPU* cp);
	bool exe_or_a_u8(CPU* cp);

	// CP
	bool exe_cp_a_a(CPU* cp);
	bool exe_cp_a_b(CPU* cp);
	bool exe_cp_a_c(CPU* cp);
	bool exe_cp_a_d(CPU* cp);
	bool exe_cp_a_e(CPU* cp);
	bool exe_cp_a_h(CPU* cp);
	bool exe_cp_a_l(CPU* cp);
	bool exe_cp_a_addr_hl(CPU* cp);
	bool exe_cp_a_u8(CPU* cp);

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

	// EXTENDED OPCODES

	// swap
	bool exe_swap_a(CPU* cp);
	bool exe_swap_b(CPU* cp);
	bool exe_swap_c(CPU* cp);
	bool exe_swap_d(CPU* cp);
	bool exe_swap_e(CPU* cp);
	bool exe_swap_h(CPU* cp);
	bool exe_swap_l(CPU* cp);
	bool exe_swap_addr_hl(CPU* cp);

	// res
	bool exe_res_0_a(CPU* cp);
	bool exe_res_0_b(CPU* cp);
	bool exe_res_0_c(CPU* cp);
	bool exe_res_0_d(CPU* cp);
	bool exe_res_0_e(CPU* cp);
	bool exe_res_0_h(CPU* cp);
	bool exe_res_0_l(CPU* cp);
	bool exe_res_0_addr_hl(CPU* cp);

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
	extern struct opcode ext_opcodes[];
}