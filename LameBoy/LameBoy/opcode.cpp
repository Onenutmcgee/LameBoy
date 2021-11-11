#include "opcode.h"
#include "CPU.h"

#define NOUSE NULL

bool OPC::exe_nop(CPU* cp)
{
	return cp->nop();
}

bool OPC::exe_di(CPU* cp)
{
	return cp->set_interrupts_enabled(false);
}

bool OPC::exe_ei(CPU* cp)
{
	return cp->set_interrupts_enabled(true);
}

bool OPC::exe_push_bc(CPU* cp)
{
	return cp->push_reg(cp->reg.bc);
}

bool OPC::exe_pop_bc(CPU* cp)
{
	return cp->pop_reg(&cp->reg.bc);
}

bool OPC::exe_push_de(CPU* cp)
{
	return cp->push_reg(cp->reg.de);
}

bool OPC::exe_pop_de(CPU* cp)
{
	return cp->pop_reg(&cp->reg.de);
}

bool OPC::exe_push_hl(CPU* cp)
{
	return cp->push_reg(cp->reg.hl);
}

bool OPC::exe_pop_hl(CPU* cp)
{
	return cp->pop_reg(&cp->reg.hl);
}

bool OPC::exe_push_af(CPU* cp)
{
	return cp->push_reg(cp->reg.af);
}

bool OPC::exe_pop_af(CPU* cp)
{
	return cp->pop_reg(&cp->reg.af);
}

// jumps
bool OPC::exe_jp_addr_pc(CPU* cp)
{
	return cp->jp_addr(cp->reg.pc);
}

bool OPC::exe_jp_hl(CPU* cp)
{
	return cp->jp_val(cp->reg.hl);
}

bool OPC::exe_jp_nz_u16(CPU* cp)
{
	return cp->jp_flag_u16(FLAG_Z, true);
}

bool OPC::exe_jp_z_u16(CPU* cp)
{
	return cp->jp_flag_u16(FLAG_Z, false);
}

bool OPC::exe_jp_nc_u16(CPU* cp)
{
	return cp->jp_flag_u16(FLAG_C, true);
}

bool OPC::exe_jp_c_u16(CPU* cp)
{
	return cp->jp_flag_u16(FLAG_C, false);
}

bool OPC::exe_jr_i8(CPU* cp)
{
	return cp->jr_i8();
}

bool OPC::exe_jr_nz_i8(CPU* cp)
{
	return cp->jr_flag_i8(FLAG_Z, true);
}

bool OPC::exe_jr_z_i8(CPU* cp)
{
	return cp->jr_flag_i8(FLAG_Z, false);
}

bool OPC::exe_jr_nc_i8(CPU* cp)
{
	return cp->jr_flag_i8(FLAG_C, true);
}

bool OPC::exe_jr_c_i8(CPU* cp)
{
	return cp->jr_flag_i8(FLAG_C, false);
}

bool OPC::exe_call_u16(CPU* cp)
{
	return cp->call_u16();
}

bool OPC::exe_call_nz_u16(CPU* cp)
{
	return cp->call_flag_u16(FLAG_Z, true);
}

bool OPC::exe_call_z_u16(CPU* cp)
{
	return cp->call_flag_u16(FLAG_Z, false);
}

bool OPC::exe_call_nc_u16(CPU* cp)
{
	return cp->call_flag_u16(FLAG_C, true);
}

bool OPC::exe_call_c_u16(CPU* cp)
{
	return cp->call_flag_u16(FLAG_C, false);
}

bool OPC::exe_rst_00(CPU* cp)
{
	return cp->call_addr(0x00);
}

bool OPC::exe_rst_08(CPU* cp)
{
	return cp->call_addr(0x08);
}

bool OPC::exe_rst_10(CPU* cp)
{
	return cp->call_addr(0x10);
}

bool OPC::exe_rst_18(CPU* cp)
{
	return cp->call_addr(0x18);
}

bool OPC::exe_rst_20(CPU* cp)
{
	return cp->call_addr(0x20);
}

bool OPC::exe_rst_28(CPU* cp)
{
	return cp->call_addr(0x28);
}

bool OPC::exe_rst_30(CPU* cp)
{
	return cp->call_addr(0x30);
}

bool OPC::exe_rst_38(CPU* cp)
{
	return cp->call_addr(0x38);
}

bool OPC::exe_ret(CPU* cp)
{
	return cp->ret();
}

bool OPC::exe_reti(CPU* cp)
{
	cp->set_interrupts_enabled(true);
	return cp->ret();
}

bool OPC::exe_ret_nz(CPU* cp)
{
	return cp->ret_flag(FLAG_Z, true);
}

bool OPC::exe_ret_z(CPU* cp)
{
	return cp->ret_flag(FLAG_Z, false);
}

bool OPC::exe_ret_nc(CPU* cp)
{
	return cp->ret_flag(FLAG_C, true);
}

bool OPC::exe_ret_c(CPU* cp)
{
	return cp->ret_flag(FLAG_C, false);
}

// 8-bit loads
// ld_a
bool OPC::exe_ld_a_b(CPU* cp)
{
	return cp->ld_a_val(cp->reg.b);
}

bool OPC::exe_ld_a_c(CPU* cp)
{
	return cp->ld_a_val(cp->reg.c);
}

bool OPC::exe_ld_a_d(CPU* cp)
{
	return cp->ld_a_val(cp->reg.d);
}

bool OPC::exe_ld_a_e(CPU* cp)
{
	return cp->ld_a_val(cp->reg.e);
}

bool OPC::exe_ld_a_h(CPU* cp)
{
	return cp->ld_a_val(cp->reg.h);
}

bool OPC::exe_ld_a_l(CPU* cp)
{
	return cp->ld_a_val(cp->reg.l);
}

bool OPC::exe_ld_a_addr_hl(CPU* cp)
{
	return cp->ld_a_addr(cp->reg.hl);
}

bool OPC::exe_ld_a_addr_hl_inc(CPU* cp)
{
	auto a = cp->ld_a_addr(cp->reg.hl);
	return a || cp->inc_reg(&cp->reg.hl);
}

bool OPC::exe_ld_a_addr_hl_dec(CPU* cp)
{
	auto a = cp->ld_a_addr(cp->reg.hl);
	return a || cp->dec_reg(&cp->reg.hl);
}

bool OPC::exe_ld_a_addr_bc(CPU* cp)
{
	return cp->ld_a_addr(cp->reg.bc);
}

bool OPC::exe_ld_a_addr_de(CPU* cp)
{
	return cp->ld_a_addr(cp->reg.de);
}

bool OPC::exe_ld_a_addr_u16(CPU* cp)
{
	return cp->ld_a_addr_immediate_u16();
}

bool OPC::exe_ld_a_addr_ff00_u8(CPU* cp)
{
	return cp->ld_a_addr_offset_u8(0xff00);
}

bool OPC::exe_ld_a_addr_ff00_c(CPU* cp)
{
	return cp->ld_a_addr(0xff00 + cp->reg.c);
}

// ld_b
bool OPC::exe_ld_b_a(CPU* cp)
{
	return cp->ld_b_val(cp->reg.b);
}

bool OPC::exe_ld_b_c(CPU* cp)
{
	return cp->ld_b_val(cp->reg.c);
}

bool OPC::exe_ld_b_d(CPU* cp)
{
	return cp->ld_b_val(cp->reg.d);
}

bool OPC::exe_ld_b_e(CPU* cp)
{
	return cp->ld_b_val(cp->reg.e);
}

bool OPC::exe_ld_b_h(CPU* cp)
{
	return cp->ld_b_val(cp->reg.h);
}

bool OPC::exe_ld_b_l(CPU* cp)
{
	return cp->ld_b_val(cp->reg.l);
}

bool OPC::exe_ld_b_addr_hl(CPU* cp)
{
	return cp->ld_b_addr(cp->reg.hl);
}

//ld_c
bool OPC::exe_ld_c_a(CPU* cp)
{
	return cp->ld_c_val(cp->reg.a);
}

bool OPC::exe_ld_c_b(CPU* cp)
{
	return cp->ld_c_val(cp->reg.b);
}

bool OPC::exe_ld_c_d(CPU* cp)
{
	return cp->ld_c_val(cp->reg.d);
}

bool OPC::exe_ld_c_e(CPU* cp)
{
	return cp->ld_c_val(cp->reg.e);
}

bool OPC::exe_ld_c_h(CPU* cp)
{
	return cp->ld_c_val(cp->reg.h);
}

bool OPC::exe_ld_c_l(CPU* cp)
{
	return cp->ld_c_val(cp->reg.l);
}

bool OPC::exe_ld_c_addr_hl(CPU* cp)
{
	return cp->ld_c_addr(cp->reg.hl);
}

//ld_d
bool OPC::exe_ld_d_a(CPU* cp)
{
	return cp->ld_d_val(cp->reg.a);
}

bool OPC::exe_ld_d_b(CPU* cp)
{
	return cp->ld_d_val(cp->reg.b);
}

bool OPC::exe_ld_d_c(CPU* cp)
{
	return cp->ld_d_val(cp->reg.c);
}

bool OPC::exe_ld_d_e(CPU* cp)
{
	return cp->ld_d_val(cp->reg.e);
}

bool OPC::exe_ld_d_h(CPU* cp)
{
	return cp->ld_d_val(cp->reg.h);
}

bool OPC::exe_ld_d_l(CPU* cp)
{
	return cp->ld_d_val(cp->reg.l);
}

bool OPC::exe_ld_d_addr_hl(CPU* cp)
{
	return cp->ld_d_addr(cp->reg.hl);
}

//ld_e
bool OPC::exe_ld_e_a(CPU* cp)
{
	return cp->ld_e_val(cp->reg.a);
}

bool OPC::exe_ld_e_b(CPU* cp)
{
	return cp->ld_e_val(cp->reg.b);
}

bool OPC::exe_ld_e_c(CPU* cp)
{
	return cp->ld_e_val(cp->reg.c);
}

bool OPC::exe_ld_e_d(CPU* cp)
{
	return cp->ld_e_val(cp->reg.d);
}

bool OPC::exe_ld_e_h(CPU* cp)
{
	return cp->ld_e_val(cp->reg.h);
}

bool OPC::exe_ld_e_l(CPU* cp)
{
	return cp->ld_e_val(cp->reg.l);
}

bool OPC::exe_ld_e_addr_hl(CPU* cp)
{
	return cp->ld_e_addr(cp->reg.hl);
}

//ld_h
bool OPC::exe_ld_h_a(CPU* cp)
{
	return cp->ld_h_val(cp->reg.a);
}

bool OPC::exe_ld_h_b(CPU* cp)
{
	return cp->ld_h_val(cp->reg.b);
}

bool OPC::exe_ld_h_c(CPU* cp)
{
	return cp->ld_h_val(cp->reg.c);
}

bool OPC::exe_ld_h_d(CPU* cp)
{
	return cp->ld_h_val(cp->reg.d);
}

bool OPC::exe_ld_h_e(CPU* cp)
{
	return cp->ld_h_val(cp->reg.e);
}

bool OPC::exe_ld_h_l(CPU* cp)
{
	return cp->ld_h_val(cp->reg.l);
}

bool OPC::exe_ld_h_addr_hl(CPU* cp)
{
	return cp->ld_h_addr(cp->reg.hl);
}

//ld_l
bool OPC::exe_ld_l_a(CPU* cp)
{
	return cp->ld_l_val(cp->reg.a);
}

bool OPC::exe_ld_l_b(CPU* cp)
{
	return cp->ld_l_val(cp->reg.b);
}

bool OPC::exe_ld_l_c(CPU* cp)
{
	return cp->ld_l_val(cp->reg.c);
}

bool OPC::exe_ld_l_d(CPU* cp)
{
	return cp->ld_l_val(cp->reg.d);
}

bool OPC::exe_ld_l_e(CPU* cp)
{
	return cp->ld_l_val(cp->reg.e);
}

bool OPC::exe_ld_l_h(CPU* cp)
{
	return cp->ld_l_val(cp->reg.h);
}

bool OPC::exe_ld_l_addr_hl(CPU* cp)
{
	return cp->ld_l_addr(cp->reg.hl);
}

//dl immediate
bool OPC::exe_ld_a_u8(CPU* cp)
{
	return cp->ld_immediate_u8_dest(&cp->reg.a);
}

bool OPC::exe_ld_b_u8(CPU* cp)
{
	return cp->ld_immediate_u8_dest(&cp->reg.b);
}

bool OPC::exe_ld_c_u8(CPU* cp)
{
	return cp->ld_immediate_u8_dest(&cp->reg.c);
}

bool OPC::exe_ld_d_u8(CPU* cp)
{
	return cp->ld_immediate_u8_dest(&cp->reg.d);
}

bool OPC::exe_ld_e_u8(CPU* cp)
{
	return cp->ld_immediate_u8_dest(&cp->reg.e);
}

bool OPC::exe_ld_h_u8(CPU* cp)
{
	return cp->ld_immediate_u8_dest(&cp->reg.h);
}

bool OPC::exe_ld_l_u8(CPU* cp)
{
	return cp->ld_immediate_u8_dest(&cp->reg.l);
}


// 8-bit writes
bool OPC::exe_ldd_hl_a(CPU* cp)
{
	return cp->ldd_addr_hl(cp->reg.a);
}

bool OPC::exe_ldi_hl_a(CPU* cp)
{
	return cp->ldi_addr_hl(cp->reg.a);
}

bool OPC::exe_ld_hl_a(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.hl, cp->reg.a);
}

bool OPC::exe_ld_hl_b(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.hl, cp->reg.b);
}

bool OPC::exe_ld_hl_c(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.hl, cp->reg.c);
}

bool OPC::exe_ld_hl_d(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.hl, cp->reg.d);
}

bool OPC::exe_ld_hl_e(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.hl, cp->reg.e);
}

bool OPC::exe_ld_hl_h(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.hl, cp->reg.h);
}

bool OPC::exe_ld_hl_l(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.hl, cp->reg.l);
}

bool OPC::exe_ld_addr_hl_u8(CPU* cp)
{
	return cp->ld_addr_immediate_u8(cp->reg.hl);
}

bool OPC::exe_ld_bc_a(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.bc, cp->reg.a);
}

bool OPC::exe_ld_de_a(CPU* cp)
{
	return cp->ld_addr_val(cp->reg.de, cp->reg.a);
}

bool OPC::exe_ld_immediate_u16_a(CPU* cp)
{
	return cp->ld_immediate_u16_addr_val(cp->reg.a);
}

bool OPC::exe_ld_ff00_immediate_u8_a(CPU* cp)
{
	return cp->ld_offset_u8_val(0xFF00, cp->reg.a);
}

bool OPC::exe_ld_ff00_c_a(CPU* cp)
{
	return cp->ld_addr_val(0xff00 + cp->reg.c, cp->reg.a);
}

// 16-bit loads
bool OPC::exe_ld_hl_u16(CPU* cp)
{
	return cp->ld_immediate_u16_dest(&cp->reg.hl);
}

bool OPC::exe_ld_bc_u16(CPU* cp)
{
	return cp->ld_immediate_u16_dest(&cp->reg.bc);
}

bool OPC::exe_ld_de_u16(CPU* cp)
{
	return cp->ld_immediate_u16_dest(&cp->reg.de);
}

bool OPC::exe_ld_sp_u16(CPU* cp)
{
	return cp->ld_immediate_u16_dest(&cp->reg.sp);
}

// ALU
bool OPC::exe_cpl_a(CPU* cp)
{
	return cp->cpl_a();
}

// add
bool OPC::exe_add_a_a(CPU* cp)
{
	return cp->add_a_val(cp->reg.a);
}

bool OPC::exe_add_a_b(CPU* cp)
{
	return cp->add_a_val(cp->reg.b);
}

bool OPC::exe_add_a_c(CPU* cp)
{
	return cp->add_a_val(cp->reg.c);
}

bool OPC::exe_add_a_d(CPU* cp)
{
	return cp->add_a_val(cp->reg.d);
}

bool OPC::exe_add_a_e(CPU* cp)
{
	return cp->add_a_val(cp->reg.e);
}

bool OPC::exe_add_a_h(CPU* cp)
{
	return cp->add_a_val(cp->reg.h);
}

bool OPC::exe_add_a_l(CPU* cp)
{
	return cp->add_a_val(cp->reg.l);
}

bool OPC::exe_add_a_addr_hl(CPU* cp)
{
	return cp->add_a_addr(cp->reg.hl);
}

bool OPC::exe_add_a_u8(CPU* cp)
{
	return cp->add_a_immediate_u8();
}

bool OPC::exe_add_hl_bc(CPU* cp)
{
	return cp->add_hl(cp->reg.bc);
}

bool OPC::exe_add_hl_de(CPU* cp)
{
	return cp->add_hl(cp->reg.de);
}

bool OPC::exe_add_hl_hl(CPU* cp)
{
	return cp->add_hl(cp->reg.hl);
}

bool OPC::exe_add_hl_sp(CPU* cp)
{
	return cp->add_hl(cp->reg.sp);
}

// adc
bool OPC::exe_adc_a_a(CPU* cp)
{
	return cp->add_carry_a_val(cp->reg.a);
}

bool OPC::exe_adc_a_b(CPU* cp)
{
	return cp->add_carry_a_val(cp->reg.b);
}

bool OPC::exe_adc_a_c(CPU* cp)
{
	return cp->add_carry_a_val(cp->reg.c);
}

bool OPC::exe_adc_a_d(CPU* cp)
{
	return cp->add_carry_a_val(cp->reg.d);
}

bool OPC::exe_adc_a_e(CPU* cp)
{
	return cp->add_carry_a_val(cp->reg.e);
}

bool OPC::exe_adc_a_h(CPU* cp)
{
	return cp->add_carry_a_val(cp->reg.h);
}

bool OPC::exe_adc_a_l(CPU* cp)
{
	return cp->add_carry_a_val(cp->reg.l);
}

bool OPC::exe_adc_a_addr_hl(CPU* cp)
{
	return cp->add_carry_a_addr(cp->reg.hl);
}

bool OPC::exe_adc_a_u8(CPU* cp)
{
	return cp->add_carry_a_immediate_u8();
}

// sub
bool OPC::exe_sub_a_a(CPU* cp)
{
	return cp->sub_a_val(cp->reg.a);
}

bool OPC::exe_sub_a_b(CPU* cp)
{
	return cp->sub_a_val(cp->reg.b);
}

bool OPC::exe_sub_a_c(CPU* cp)
{
	return cp->sub_a_val(cp->reg.c);
}

bool OPC::exe_sub_a_d(CPU* cp)
{
	return cp->sub_a_val(cp->reg.d);
}

bool OPC::exe_sub_a_e(CPU* cp)
{
	return cp->sub_a_val(cp->reg.e);
}

bool OPC::exe_sub_a_h(CPU* cp)
{
	return cp->sub_a_val(cp->reg.h);
}

bool OPC::exe_sub_a_l(CPU* cp)
{
	return cp->sub_a_val(cp->reg.l);
}

bool OPC::exe_sub_a_addr_hl(CPU* cp)
{
	return cp->sub_a_addr(cp->reg.hl);
}

bool OPC::exe_sub_a_u8(CPU* cp)
{
	return cp->sub_a_immediate_u8();
}

// sbc
bool OPC::exe_sbc_a_a(CPU* cp)
{
	return cp->sub_carry_a_val(cp->reg.a);
}

bool OPC::exe_sbc_a_b(CPU* cp)
{
	return cp->sub_carry_a_val(cp->reg.b);
}

bool OPC::exe_sbc_a_c(CPU* cp)
{
	return cp->sub_carry_a_val(cp->reg.c);
}

bool OPC::exe_sbc_a_d(CPU* cp)
{
	return cp->sub_carry_a_val(cp->reg.d);
}

bool OPC::exe_sbc_a_e(CPU* cp)
{
	return cp->sub_carry_a_val(cp->reg.e);
}

bool OPC::exe_sbc_a_h(CPU* cp)
{
	return cp->sub_carry_a_val(cp->reg.h);
}

bool OPC::exe_sbc_a_l(CPU* cp)
{
	return cp->sub_carry_a_val(cp->reg.l);
}

bool OPC::exe_sbc_a_addr_hl(CPU* cp)
{
	return cp->sub_carry_a_addr(cp->reg.hl);
}

bool OPC::exe_sbc_a_u8(CPU* cp)
{
	return cp->sub_carry_a_immediate_u8();
}
 
// XOR
bool OPC::exe_xor_a_a(CPU* cp)
{
	return cp->xor_a_val(cp->reg.a);
}

bool OPC::exe_xor_a_b(CPU* cp)
{
	return cp->xor_a_val(cp->reg.b);
}

bool OPC::exe_xor_a_c(CPU* cp)
{
	return cp->xor_a_val(cp->reg.c);
}

bool OPC::exe_xor_a_d(CPU* cp)
{
	return cp->xor_a_val(cp->reg.d);
}

bool OPC::exe_xor_a_e(CPU* cp)
{
	return cp->xor_a_val(cp->reg.e);
}

bool OPC::exe_xor_a_h(CPU* cp)
{
	return cp->xor_a_val(cp->reg.h);
}

bool OPC::exe_xor_a_l(CPU* cp)
{
	return cp->xor_a_val(cp->reg.l);
}

bool OPC::exe_xor_a_addr_hl(CPU* cp)
{
	return cp->xor_a_addr(cp->reg.hl);
}

bool OPC::exe_xor_a_u8(CPU* cp)
{
	return cp->xor_a_immediate_u8();
}

// or
bool OPC::exe_or_a_a(CPU* cp)
{
	return cp->or_a_val(cp->reg.a);
}

bool OPC::exe_or_a_b(CPU* cp)
{
	return cp->or_a_val(cp->reg.b);
}

bool OPC::exe_or_a_c(CPU* cp)
{
	return cp->or_a_val(cp->reg.c);
}

bool OPC::exe_or_a_d(CPU* cp)
{
	return cp->or_a_val(cp->reg.d);
}

bool OPC::exe_or_a_e(CPU* cp)
{
	return cp->or_a_val(cp->reg.e);
}

bool OPC::exe_or_a_h(CPU* cp)
{
	return cp->or_a_val(cp->reg.h);
}

bool OPC::exe_or_a_l(CPU* cp)
{
	return cp->or_a_val(cp->reg.l);
}

bool OPC::exe_or_a_addr_hl(CPU* cp)
{
	return cp->or_a_addr(cp->reg.hl);
}

bool OPC::exe_or_a_u8(CPU* cp)
{
	return cp->or_a_immediate_u8();
}

// and
bool OPC::exe_and_a_a(CPU* cp)
{
	return cp->and_a_val(cp->reg.a);
}

bool OPC::exe_and_a_b(CPU* cp)
{
	return cp->and_a_val(cp->reg.b);
}

bool OPC::exe_and_a_c(CPU* cp)
{
	return cp->and_a_val(cp->reg.c);
}

bool OPC::exe_and_a_d(CPU* cp)
{
	return cp->and_a_val(cp->reg.d);
}

bool OPC::exe_and_a_e(CPU* cp)
{
	return cp->and_a_val(cp->reg.e);
}

bool OPC::exe_and_a_h(CPU* cp)
{
	return cp->and_a_val(cp->reg.h);
}

bool OPC::exe_and_a_l(CPU* cp)
{
	return cp->and_a_val(cp->reg.l);
}

bool OPC::exe_and_a_addr_hl(CPU* cp)
{
	return cp->and_a_addr(cp->reg.hl);
}

bool OPC::exe_and_a_u8(CPU* cp)
{
	return cp->and_a_immediate_u8();
}

// cp
bool OPC::exe_cp_a_a(CPU* cp)
{
	return cp->cp_a_val(cp->reg.a);
}

bool OPC::exe_cp_a_b(CPU* cp)
{
	return cp->cp_a_val(cp->reg.b);
}

bool OPC::exe_cp_a_c(CPU* cp)
{
	return cp->cp_a_val(cp->reg.c);
}

bool OPC::exe_cp_a_d(CPU* cp)
{
	return cp->cp_a_val(cp->reg.d);
}

bool OPC::exe_cp_a_e(CPU* cp)
{
	return cp->cp_a_val(cp->reg.e);
}

bool OPC::exe_cp_a_h(CPU* cp)
{
	return cp->cp_a_val(cp->reg.h);
}

bool OPC::exe_cp_a_l(CPU* cp)
{
	return cp->cp_a_val(cp->reg.l);
}

bool OPC::exe_cp_a_addr_hl(CPU* cp)
{
	return cp->cp_a_addr(cp->reg.hl);
}

bool OPC::exe_cp_a_u8(CPU* cp)
{
	return cp->cp_a_immediate_u8();
}

// INC
bool OPC::exe_inc_a(CPU* cp)
{
	return cp->inc_reg(&cp->reg.a);
}

bool OPC::exe_inc_b(CPU* cp)
{
	return cp->inc_reg(&cp->reg.b);
}

bool OPC::exe_inc_c(CPU* cp)
{
	return cp->inc_reg(&cp->reg.c);
}

bool OPC::exe_inc_d(CPU* cp)
{
	return cp->inc_reg(&cp->reg.d);
}

bool OPC::exe_inc_e(CPU* cp)
{
	return cp->inc_reg(&cp->reg.e);
}

bool OPC::exe_inc_h(CPU* cp)
{
	return cp->inc_reg(&cp->reg.h);
}

bool OPC::exe_inc_l(CPU* cp)
{
	return cp->inc_reg(&cp->reg.l);
}

bool OPC::exe_inc_bc(CPU* cp)
{
	return cp->inc_reg(&cp->reg.bc);
}

bool OPC::exe_inc_de(CPU* cp)
{
	return cp->inc_reg(&cp->reg.de);
}

bool OPC::exe_inc_hl(CPU* cp)
{
	return cp->inc_reg(&cp->reg.hl);
}

bool OPC::exe_inc_sp(CPU* cp)
{
	return cp->inc_reg(&cp->reg.sp);
}

// DEC
bool OPC::exe_dec_a(CPU* cp)
{
	return cp->dec_reg(&cp->reg.a);
}

bool OPC::exe_dec_b(CPU* cp)
{
	return cp->dec_reg(&cp->reg.b);
}

bool OPC::exe_dec_c(CPU* cp)
{
	return cp->dec_reg(&cp->reg.c);
}

bool OPC::exe_dec_d(CPU* cp)
{
	return cp->dec_reg(&cp->reg.d);
}

bool OPC::exe_dec_e(CPU* cp)
{
	return cp->dec_reg(&cp->reg.e);
}

bool OPC::exe_dec_h(CPU* cp)
{
	return cp->dec_reg(&cp->reg.h);
}

bool OPC::exe_dec_l(CPU* cp)
{
	return cp->dec_reg(&cp->reg.l);
}

bool OPC::exe_dec_bc(CPU* cp)
{
	return cp->dec_reg(&cp->reg.bc);
}

bool OPC::exe_dec_de(CPU* cp)
{
	return cp->dec_reg(&cp->reg.de);
}

bool OPC::exe_dec_hl(CPU* cp)
{
	return cp->dec_reg(&cp->reg.hl);
}

bool OPC::exe_dec_sp(CPU* cp)
{
	return cp->dec_reg(&cp->reg.sp);
}

struct OPC::opcode OPC::opcodes[256] = {
			{ 0x00, "NOP"		, 1, 1, 1, "----", exe_nop},
			{ 0x01, "LD BC,u16"	, 3, 3, 3, "----", exe_ld_bc_u16},
			{ 0x02, "LD (BC),A"	, 1, 2, 2, "----", exe_ld_bc_a},
			{ 0x03, "INC BC"	, 1, 2, 2, "----", exe_inc_bc},
			{ 0x04, "INC B"		, 1, 1, 1, "Z0H-", exe_inc_b},
			{ 0x05, "DEC B"		, 1, 1, 1, "Z1H-", exe_dec_b},
			{ 0x06, "LD B,u8"	, 2, 2, 2, "----", exe_ld_b_u8 },
			{ 0x07, "RLCA"		, 1, 1, 1, "000C"},
			{ 0x08, "LD (u16),SP",3, 5, 5, "----"},
			{ 0x09, "ADD HL,BC"	, 1, 2, 2, "-0HC", exe_add_hl_bc},
			{ 0x0A, "LD A,(BC)"	, 1, 2, 2, "----", exe_ld_a_addr_bc},
			{ 0x0B, "DEC BC"	, 1, 2, 2, "----", exe_dec_bc},
			{ 0x0C, "INC C"		, 1, 1, 1, "Z0H-", exe_inc_c},
			{ 0x0D, "DEC C"		, 1, 1, 1, "Z1H-", exe_dec_c},
			{ 0x0E, "LD C,u8"	, 2, 2, 2, "----", exe_ld_c_u8},
			{ 0x0F, "RRCA"		, 1, 1, 1, "000C"},
			{ 0x10, "STOP"		, 2, 1, 1, "----"},
			{ 0x11, "LD DE,u16"	, 3, 3, 3, "----", exe_ld_de_u16},
			{ 0x12, "LD (DE),A"	, 1, 2, 2, "----", exe_ld_de_a },
			{ 0x13, "INC DE"	, 1, 2, 2, "----", exe_inc_de},
			{ 0x14, "INC D"		, 1, 1, 1, "Z0H-", exe_inc_d},
			{ 0x15, "DEC D"		, 1, 1, 1, "Z1H-", exe_dec_d},
			{ 0x16, "LD D,u8"	, 2, 2, 2, "----", exe_ld_d_u8},
			{ 0x17, "RLA"		, 1, 1, 1, "000C"},
			{ 0x18, "JR i8"		, 2, 3, 3, "----", exe_jr_i8 },
			{ 0x19, "ADD HL,DE"	, 1, 2, 2, "-0HC", exe_add_hl_de },
			{ 0x1A, "LD A,(DE)"	, 1, 2, 2, "----", exe_ld_a_addr_de},
			{ 0x1B, "DEC DE"	, 1, 2, 2, "----", exe_dec_de},
			{ 0x1C, "INC E"		, 1, 1, 1, "Z0H-", exe_inc_e},
			{ 0x1D, "DEC E"		, 1, 1, 1, "Z1H-", exe_dec_e},
			{ 0x1E, "LD E,u8"	, 2, 2, 2, "----", exe_ld_e_u8},
			{ 0x1F, "RRA"		, 1, 1, 1, "000C"},
			{ 0x20, "JR NZ,i8"	, 2, 2, 3, "----", exe_jr_nz_i8 },
			{ 0x21, "LD HL,u16"	, 3, 3, 3, "----", exe_ld_hl_u16},
			{ 0x22, "LD (HL+),A", 1, 2, 2, "----", exe_ldi_hl_a},
			{ 0x23, "INC HL"	, 1, 2, 2, "----", exe_inc_hl},
			{ 0x24, "INC H"		, 1, 1, 1, "Z0H-", exe_inc_h},
			{ 0x25, "DEC H"		, 1, 1, 1, "Z1H-", exe_dec_h},
			{ 0x26, "LD H,u8"	, 2, 2, 2, "----", exe_ld_h_u8},
			{ 0x27, "DAA"		, 1, 1, 1, "Z-0C"},
			{ 0x28, "JR Z,i8"	, 2, 2, 3, "----", exe_jr_z_i8},
			{ 0x29, "ADD HL,HL"	, 1, 2, 2, "-0HC", exe_add_hl_hl },
			{ 0x2A, "LD A,(HL+)", 1, 2, 2, "----", exe_ld_a_addr_hl_inc},
			{ 0x2B, "DEC HL"	, 1, 2, 2, "----", exe_dec_hl},
			{ 0x2C, "INC L"		, 1, 1, 1, "Z0H-", exe_inc_l},
			{ 0x2D, "DEC L"		, 1, 1, 1, "Z1H-", exe_dec_l},
			{ 0x2E, "LD L,u8"	, 2, 2, 2, "----", exe_ld_l_u8},
			{ 0x2F, "CPL"		, 1, 1, 1, "-11-", exe_cpl_a },
			{ 0x30, "JR NC,i8"	, 2, 2, 3, "----", exe_jr_nc_i8},
			{ 0x31, "LD SP,u16"	, 3, 3, 3, "----", exe_ld_sp_u16},
			{ 0x32, "LD (HL-),A", 1, 2, 2, "----", exe_ldd_hl_a},
			{ 0x33, "INC SP"	, 1, 2, 2, "----", exe_inc_sp},
			{ 0x34, "INC (HL)"	, 1, 3, 3, "Z0H-"},
			{ 0x35, "DEC (HL)"	, 1, 3, 3, "Z1H-"},
			{ 0x36, "LD (HL),u8", 2, 3, 3, "----", exe_ld_addr_hl_u8 },
			{ 0x37, "SCF"		, 1, 1, 1, "-001"},
			{ 0x38, "JR C,i8"	, 2, 2, 3, "----", exe_jr_c_i8},
			{ 0x39, "ADD HL,SP"	, 1, 2, 2, "-0HC", exe_add_hl_sp },
			{ 0x3A, "LD A,(HL-)", 1, 2, 2, "----", exe_ld_a_addr_hl_dec},
			{ 0x3B, "DEC SP"	, 1, 2, 2, "----", exe_dec_sp},
			{ 0x3C, "INC A"		, 1, 1, 1, "Z0H-", exe_inc_a},
			{ 0x3D, "DEC A"		, 1, 1, 1, "Z1H-", exe_dec_a},
			{ 0x3E, "LD A,u8"	, 2, 2, 2, "----", exe_ld_a_u8},
			{ 0x3F, "CCF"		, 1, 1, 1, "-00C"},
			{ 0x40, "LD B,B"	, 1, 1, 1, "----", exe_nop},
			{ 0x41, "LD B,C"	, 1, 1, 1, "----", exe_ld_b_c },
			{ 0x42, "LD B,D"	, 1, 1, 1, "----", exe_ld_b_d },
			{ 0x43, "LD B,E"	, 1, 1, 1, "----", exe_ld_b_e },
			{ 0x44, "LD B,H"	, 1, 1, 1, "----", exe_ld_b_h },
			{ 0x45, "LD B,L"	, 1, 1, 1, "----", exe_ld_b_l },
			{ 0x46, "LD B,(HL)"	, 1, 2, 2, "----", exe_ld_b_addr_hl },
			{ 0x47, "LD B,A"	, 1, 1, 1, "----", exe_ld_b_a },
			{ 0x48, "LD C,B"	, 1, 1, 1, "----", exe_ld_c_b },
			{ 0x49, "LD C,C"	, 1, 1, 1, "----", exe_nop },
			{ 0x4A, "LD C,D"	, 1, 1, 1, "----", exe_ld_c_d },
			{ 0x4B, "LD C,E"	, 1, 1, 1, "----", exe_ld_c_e },
			{ 0x4C, "LD C,H"	, 1, 1, 1, "----", exe_ld_c_h },
			{ 0x4D, "LD C,L"	, 1, 1, 1, "----", exe_ld_c_l },
			{ 0x4E, "LD C,(HL)"	, 1, 2, 2, "----", exe_ld_c_addr_hl },
			{ 0x4F, "LD C,A"	, 1, 1, 1, "----", exe_ld_c_a },
			{ 0x50, "LD D,B"	, 1, 1, 1, "----", exe_ld_d_b },
			{ 0x51, "LD D,C"	, 1, 1, 1, "----", exe_ld_d_c },
			{ 0x52, "LD D,D"	, 1, 1, 1, "----", exe_nop },
			{ 0x53, "LD D,E"	, 1, 1, 1, "----", exe_ld_d_e },
			{ 0x54, "LD D,H"	, 1, 1, 1, "----", exe_ld_d_h },
			{ 0x55, "LD D,L"	, 1, 1, 1, "----", exe_ld_d_l },
			{ 0x56, "LD D,(HL)"	, 1, 2, 2, "----", exe_ld_d_addr_hl },
			{ 0x57, "LD D,A"	, 1, 1, 1, "----", exe_ld_d_a },
			{ 0x58, "LD E,B"	, 1, 1, 1, "----", exe_ld_e_b },
			{ 0x59, "LD E,C"	, 1, 1, 1, "----", exe_ld_e_c },
			{ 0x5A, "LD E,D"	, 1, 1, 1, "----", exe_ld_e_d },
			{ 0x5B, "LD E,E"	, 1, 1, 1, "----", exe_nop },
			{ 0x5C, "LD E,H"	, 1, 1, 1, "----", exe_ld_e_h },
			{ 0x5D, "LD E,L"	, 1, 1, 1, "----", exe_ld_e_l },
			{ 0x5E, "LD E,(HL)"	, 1, 2, 2, "----", exe_ld_e_addr_hl },
			{ 0x5F, "LD E,A"	, 1, 1, 1, "----", exe_ld_e_a },
			{ 0x60, "LD H,B"	, 1, 1, 1, "----", exe_ld_h_b },
			{ 0x61, "LD H,C"	, 1, 1, 1, "----", exe_ld_h_c },
			{ 0x62, "LD H,D"	, 1, 1, 1, "----", exe_ld_h_d },
			{ 0x63, "LD H,E"	, 1, 1, 1, "----", exe_ld_h_e },
			{ 0x64, "LD H,H"	, 1, 1, 1, "----", exe_nop },
			{ 0x65, "LD H,L"	, 1, 1, 1, "----", exe_ld_h_l },
			{ 0x66, "LD H,(HL)"	, 1, 2, 2, "----", exe_ld_h_addr_hl },
			{ 0x67, "LD H,A"	, 1, 1, 1, "----", exe_ld_h_a },
			{ 0x68, "LD L,B"	, 1, 1, 1, "----", exe_ld_l_b },
			{ 0x69, "LD L,C"	, 1, 1, 1, "----", exe_ld_l_c },
			{ 0x6A, "LD L,D"	, 1, 1, 1, "----", exe_ld_l_d },
			{ 0x6B, "LD L,E"	, 1, 1, 1, "----", exe_ld_l_e },
			{ 0x6C, "LD L,H"	, 1, 1, 1, "----", exe_ld_l_h },
			{ 0x6D, "LD L,L"	, 1, 1, 1, "----", exe_nop },
			{ 0x6E, "LD L,(HL)"	, 1, 2, 2, "----", exe_ld_l_addr_hl },
			{ 0x6F, "LD L,A"	, 1, 1, 1, "----", exe_ld_l_a },
			{ 0x70, "LD (HL),B"	, 1, 2, 2, "----", exe_ld_hl_b },
			{ 0x71, "LD (HL),C"	, 1, 2, 2, "----", exe_ld_hl_c},
			{ 0x72, "LD (HL),D"	, 1, 2, 2, "----", exe_ld_hl_d },
			{ 0x73, "LD (HL),E"	, 1, 2, 2, "----", exe_ld_hl_e },
			{ 0x74, "LD (HL),H"	, 1, 2, 2, "----", exe_ld_hl_h },
			{ 0x75, "LD (HL),L"	, 1, 2, 2, "----", exe_ld_hl_l },
			{ 0x76, "HALT"		, 1, 1, 1, "----"},
			{ 0x77, "LD (HL),A"	, 1, 2, 2, "----", exe_ld_hl_a },
			{ 0x78, "LD A,B"	, 1, 1, 1, "----", exe_ld_a_b },
			{ 0x79, "LD A,C"	, 1, 1, 1, "----", exe_ld_a_c },
			{ 0x7A, "LD A,D"	, 1, 1, 1, "----", exe_ld_a_d },
			{ 0x7B, "LD A,E"	, 1, 1, 1, "----", exe_ld_a_e },
			{ 0x7C, "LD A,H"	, 1, 1, 1, "----", exe_ld_a_h },
			{ 0x7D, "LD A,L"	, 1, 1, 1, "----", exe_ld_a_l },
			{ 0x7E, "LD A,(HL)"	, 1, 2, 2, "----", exe_ld_a_addr_hl },
			{ 0x7F, "LD A,A"	, 1, 1, 1, "----", exe_nop},
			{ 0x80, "ADD A,B"	, 1, 1, 1, "Z0HC", exe_add_a_b },
			{ 0x81, "ADD A,C"	, 1, 1, 1, "Z0HC", exe_add_a_c },
			{ 0x82, "ADD A,D"	, 1, 1, 1, "Z0HC", exe_add_a_d },
			{ 0x83, "ADD A,E"	, 1, 1, 1, "Z0HC", exe_add_a_e },
			{ 0x84, "ADD A,H"	, 1, 1, 1, "Z0HC", exe_add_a_h },
			{ 0x85, "ADD A,L"	, 1, 1, 1, "Z0HC", exe_add_a_l },
			{ 0x86, "ADD A,(HL)", 1, 2, 2, "Z0HC", exe_add_a_addr_hl },
			{ 0x87, "ADD A,A"	, 1, 1, 1, "Z0HC", exe_add_a_a },
			{ 0x88, "ADC A,B"	, 1, 1, 1, "Z0HC", exe_adc_a_b },
			{ 0x89, "ADC A,C"	, 1, 1, 1, "Z0HC", exe_adc_a_c },
			{ 0x8A, "ADC A,D"	, 1, 1, 1, "Z0HC", exe_adc_a_d },
			{ 0x8B, "ADC A,E"	, 1, 1, 1, "Z0HC", exe_adc_a_e },
			{ 0x8C, "ADC A,H"	, 1, 1, 1, "Z0HC", exe_adc_a_h },
			{ 0x8D, "ADC A,L"	, 1, 1, 1, "Z0HC", exe_adc_a_l },
			{ 0x8E, "ADC A,(HL)", 1, 2, 2, "Z0HC", exe_adc_a_addr_hl },
			{ 0x8F, "ADC A,A"	, 1, 1, 1, "Z0HC", exe_adc_a_a },
			{ 0x90, "SUB A,B"	, 1, 1, 1, "Z1HC", exe_sub_a_b },
			{ 0x91, "SUB A,C"	, 1, 1, 1, "Z1HC", exe_sub_a_c },
			{ 0x92, "SUB A,D"	, 1, 1, 1, "Z1HC", exe_sub_a_d },
			{ 0x93, "SUB A,E"	, 1, 1, 1, "Z1HC", exe_sub_a_e },
			{ 0x94, "SUB A,H"	, 1, 1, 1, "Z1HC", exe_sub_a_h },
			{ 0x95, "SUB A,L"	, 1, 1, 1, "Z1HC", exe_sub_a_l },
			{ 0x96, "SUB A,(HL)", 1, 2, 2, "Z1HC", exe_sub_a_addr_hl },
			{ 0x97, "SUB A,A"	, 1, 1, 1, "Z1HC", exe_sub_a_a },
			{ 0x98, "SBC A,B"	, 1, 1, 1, "Z1HC", exe_sbc_a_b },
			{ 0x99, "SBC A,C"	, 1, 1, 1, "Z1HC", exe_sbc_a_c },
			{ 0x9A, "SBC A,D"	, 1, 1, 1, "Z1HC", exe_sbc_a_d },
			{ 0x9B, "SBC A,E"	, 1, 1, 1, "Z1HC", exe_sbc_a_e },
			{ 0x9C, "SBC A,H"	, 1, 1, 1, "Z1HC", exe_sbc_a_h },
			{ 0x9D, "SBC A,L"	, 1, 1, 1, "Z1HC", exe_sbc_a_l },
			{ 0x9E, "SBC A,(HL)", 1, 2, 2, "Z1HC", exe_sbc_a_addr_hl },
			{ 0x9F, "SBC A,A"	, 1, 1, 1, "Z1HC", exe_sbc_a_a },
			{ 0xA0, "AND A,B"	, 1, 1, 1, "Z010", exe_and_a_b },
			{ 0xA1, "AND A,C"	, 1, 1, 1, "Z010", exe_and_a_c },
			{ 0xA2, "AND A,D"	, 1, 1, 1, "Z010", exe_and_a_d },
			{ 0xA3, "AND A,E"	, 1, 1, 1, "Z010", exe_and_a_e },
			{ 0xA4, "AND A,H"	, 1, 1, 1, "Z010", exe_and_a_h },
			{ 0xA5, "AND A,L"	, 1, 1, 1, "Z010", exe_and_a_l },
			{ 0xA6, "AND A,(HL)", 1, 2, 2, "Z010", exe_and_a_addr_hl },
			{ 0xA7, "AND A,A"	, 1, 1, 1, "Z010", exe_and_a_a },
			{ 0xA8, "XOR A,B"	, 1, 1, 1, "Z000", exe_xor_a_b },
			{ 0xA9, "XOR A,C"	, 1, 1, 1, "Z000", exe_xor_a_c },
			{ 0xAA, "XOR A,D"	, 1, 1, 1, "Z000", exe_xor_a_d },
			{ 0xAB, "XOR A,E"	, 1, 1, 1, "Z000", exe_xor_a_e },
			{ 0xAC, "XOR A,H"	, 1, 1, 1, "Z000", exe_xor_a_h },
			{ 0xAD, "XOR A,L"	, 1, 1, 1, "Z000", exe_xor_a_l },
			{ 0xAE, "XOR A,(HL)", 1, 2, 2, "Z000", exe_xor_a_addr_hl },
			{ 0xAF, "XOR A,A"	, 1, 1, 1, "Z000", exe_xor_a_a },
			{ 0xB0, "OR A,B"	, 1, 1, 1, "Z000", exe_or_a_b},
			{ 0xB1, "OR A,C"	, 1, 1, 1, "Z000", exe_or_a_c },
			{ 0xB2, "OR A,D"	, 1, 1, 1, "Z000", exe_or_a_d },
			{ 0xB3, "OR A,E"	, 1, 1, 1, "Z000", exe_or_a_e },
			{ 0xB4, "OR A,H"	, 1, 1, 1, "Z000", exe_or_a_h },
			{ 0xB5, "OR A,L"	, 1, 1, 1, "Z000", exe_or_a_l },
			{ 0xB6, "OR A,(HL)"	, 1, 2, 2, "Z000", exe_or_a_addr_hl },
			{ 0xB7, "OR A,A"	, 1, 1, 1, "Z000", exe_or_a_a },
			{ 0xB8, "CP A,B"	, 1, 1, 1, "Z1HC", exe_cp_a_b },
			{ 0xB9, "CP A,C"	, 1, 1, 1, "Z1HC", exe_cp_a_c },
			{ 0xBA, "CP A,D"	, 1, 1, 1, "Z1HC", exe_cp_a_d },
			{ 0xBB, "CP A,E"	, 1, 1, 1, "Z1HC", exe_cp_a_e },
			{ 0xBC, "CP A,H"	, 1, 1, 1, "Z1HC", exe_cp_a_h },
			{ 0xBD, "CP A,L"	, 1, 1, 1, "Z1HC", exe_cp_a_l },
			{ 0xBE, "CP A,(HL)"	, 1, 2, 2, "Z1HC", exe_cp_a_addr_hl },
			{ 0xBF, "CP A,A"	, 1, 1, 1, "Z1HC", exe_cp_a_a },
			{ 0xC0, "RET NZ"	, 1, 2, 5, "----", exe_ret_nz},
			{ 0xC1, "POP BC"	, 1, 3, 3, "----", exe_pop_bc},
			{ 0xC2, "JP NZ,u16"	, 3, 3, 4, "----", exe_jp_nz_u16},
			{ 0xC3, "JP u16"	, 3, 4, 4, "----", exe_jp_addr_pc},
			{ 0xC4, "CALL NZ,u16",3, 3, 6, "----", exe_call_nz_u16 },
			{ 0xC5, "PUSH BC"	, 1, 4, 4, "----", exe_push_bc},
			{ 0xC6, "ADD A,u8"	, 2, 2, 2, "Z0HC", exe_add_a_u8 },
			{ 0xC7, "RST 00h"	, 1, 4, 4, "----", exe_rst_00 },
			{ 0xC8, "RET Z"		, 1, 2, 5, "----", exe_ret_z },
			{ 0xC9, "RET"		, 1, 4, 4, "----", exe_ret },
			{ 0xCA, "JP Z,u16"	, 3, 3, 4, "----", exe_jp_z_u16 },
			{ 0xCB, "PREFIX CB"	, 1, 1, 1, "----", NULL /* extended */},
			{ 0xCC, "CALL Z,u16", 3, 3, 6, "----", exe_call_z_u16 },
			{ 0xCD, "CALL u16"	, 3, 6, 6, "----", exe_call_u16 },
			{ 0xCE, "ADC A,u8"	, 2, 2, 2, "Z0HC", exe_adc_a_u8 },
			{ 0xCF, "RST 08h"	, 1, 4, 4, "----", exe_rst_08 },
			{ 0xD0, "RET NC"	, 1, 2, 5, "----", exe_ret_nc },
			{ 0xD1, "POP DE"	, 1, 3, 3, "----", exe_pop_de },
			{ 0xD2, "JP NC,u16"	, 3, 3, 4, "----", exe_jp_nc_u16 },
			{ 0xD3, "UNUSED"	, 0, 0, 0, "----", NOUSE},
			{ 0xD4, "CALL NC,u16",3, 3, 6, "----", exe_call_nc_u16 },
			{ 0xD5, "PUSH DE"	, 1, 4, 4, "----", exe_push_de },
			{ 0xD6, "SUB A,u8"	, 2, 2, 2, "Z1HC", exe_sub_a_u8 },
			{ 0xD7, "RST 10h"	, 1, 4, 4, "----", exe_rst_10 },
			{ 0xD8, "RET C"		, 1, 2, 5, "----", exe_ret_c },
			{ 0xD9, "RETI"		, 1, 4, 4, "----", exe_reti},
			{ 0xDA, "JP C,u16"	, 3, 3, 4, "----", exe_jp_c_u16 },
			{ 0xDB, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xDC, "CALL C,u16", 3, 3, 6, "----", exe_call_c_u16 },
			{ 0xDD, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xDE, "SBC A,u8"	, 2, 2, 2, "Z1HC", exe_sbc_a_u8 },
			{ 0xDF, "RST 18h"	, 1, 4, 4, "----", exe_rst_18 },
			{ 0xE0, "LD (FF00+u8),A",2,3,3,"----", exe_ld_ff00_immediate_u8_a },
			{ 0xE1, "POP HL"	, 1, 3, 3, "----", exe_pop_hl },
			{ 0xE2, "LD (FF00+C),A",1,2,2, "----", exe_ld_ff00_c_a },
			{ 0xE3, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xE4, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xE5, "PUSH HL"	, 1, 4, 4, "----", exe_push_hl },
			{ 0xE6, "AND A,u8"	, 2, 2, 2, "Z010", exe_and_a_u8 },
			{ 0xE7, "RST 20h"	, 1, 4, 4, "----", exe_rst_20 },
			{ 0xE8, "ADD SP,i8"	, 2, 4, 4, "00HC"},
			{ 0xE9, "JP HL"		, 1, 1, 1, "----", exe_jp_hl },
			{ 0xEA, "LD (u16),A", 3, 4, 4, "----", exe_ld_immediate_u16_a },
			{ 0xEB, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xEC, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xED, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xEE, "XOR A,u8"	, 2, 2, 2, "Z000", exe_xor_a_u8 },
			{ 0xEF, "RST 28h"	, 1, 4, 4, "----", exe_rst_28 },
			{ 0xF0, "LD A,(FF00+u8)",2,3,3,"----", exe_ld_a_addr_ff00_u8 },
			{ 0xF1, "POP AF"	, 1, 3, 3, "ZNHC", exe_pop_af },
			{ 0xF2, "LD A,(FF00+C)",1,2,2, "----", exe_ld_a_addr_ff00_c },
			{ 0xF3, "DI"		, 1, 1, 1, "----", exe_di },
			{ 0xF4, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xF5, "PUSH AF"	, 1, 4, 4, "----", exe_push_af },
			{ 0xF6, "OR A,u8"	, 2, 2, 2, "Z000", exe_or_a_u8 },
			{ 0xF7, "RST 30h"	, 1, 4, 4, "----", exe_rst_30 },
			{ 0xF8, "LD HL,SP+i8",2, 3, 3, "00HC"},
			{ 0xF9, "LD SP,HL"	, 1, 2, 2, "----"},
			{ 0xFA, "LD A,(u16)", 3, 4, 4, "----", exe_ld_a_addr_u16 },
			{ 0xFB, "EI"		, 1, 1, 1, "----", exe_ei},
			{ 0xFC, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xFD, "UNUSED"	, 0, 0, 0, "----", NOUSE },
			{ 0xFE, "CP A,u8"	, 2, 2, 2, "Z1HC", exe_cp_a_u8 },
			{ 0xFF, "RST 38h"	, 1, 4, 4, "----", exe_rst_38 }
};