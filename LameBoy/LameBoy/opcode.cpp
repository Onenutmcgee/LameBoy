#include "opcode.h"
#include "CPU.h"

bool OPC::exe_nop(CPU* cp)
{
	return cp->nop();
}

// jumps
bool OPC::exe_jp_addr_pc(CPU* cp)
{
	return cp->jp_addr(cp->reg.pc);
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
// XOR
bool OPC::exe_xor_a_a(CPU* cp)
{
	return cp->xor_a_n(cp->reg.a);
}

bool OPC::exe_xor_a_b(CPU* cp)
{
	return cp->xor_a_n(cp->reg.b);
}

bool OPC::exe_xor_a_c(CPU* cp)
{
	return cp->xor_a_n(cp->reg.c);
}

bool OPC::exe_xor_a_d(CPU* cp)
{
	return cp->xor_a_n(cp->reg.d);
}

bool OPC::exe_xor_a_e(CPU* cp)
{
	return cp->xor_a_n(cp->reg.e);
}

bool OPC::exe_xor_a_h(CPU* cp)
{
	return cp->xor_a_n(cp->reg.h);
}

bool OPC::exe_xor_a_l(CPU* cp)
{
	return cp->xor_a_n(cp->reg.l);
}

bool OPC::exe_xor_a_addr_hl(CPU* cp)
{
	return cp->xor_a_addr(cp->reg.hl);
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
	return cp->inc_reg(&cp->reg.bc);
}

bool OPC::exe_inc_hl(CPU* cp)
{
	return cp->inc_reg(&cp->reg.bc);
}

bool OPC::exe_inc_sp(CPU* cp)
{
	return cp->inc_reg(&cp->reg.bc);
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
	return cp->dec_reg(&cp->reg.bc);
}

bool OPC::exe_dec_hl(CPU* cp)
{
	return cp->dec_reg(&cp->reg.bc);
}

bool OPC::exe_dec_sp(CPU* cp)
{
	return cp->dec_reg(&cp->reg.bc);
}

struct OPC::opcode OPC::opcodes[256] = {
			{ 0x00, "NOP"		, 1, 1, 1, "----", exe_nop},
			{ 0x01, "LD BC,u16"	, 3, 3, 3, "----", exe_ld_bc_u16},
			{ 0x02, "LD (BC),A"	, 1, 2, 2, "----"},
			{ 0x03, "INC BC"	, 1, 2, 2, "----", exe_inc_bc},
			{ 0x04, "INC B"		, 1, 1, 1, "Z0H-", exe_inc_b},
			{ 0x05, "DEC B"		, 1, 1, 1, "Z1H-", exe_dec_b},
			{ 0x06, "LD B,u8"	, 2, 2, 2, "----", exe_ld_b_u8 },
			{ 0x07, "RLCA"		, 1, 1, 1, "000C"},
			{ 0x08, "LD (u16),SP",3, 5, 5, "----"},
			{ 0x09, "ADD HL,BC"	, 1, 2, 2, "-0HC"},
			{ 0x0A, "LD A,(BC)"	, 1, 2, 2, "----"},
			{ 0x0B, "DEC BC"	, 1, 2, 2, "----", exe_dec_bc},
			{ 0x0C, "INC C"		, 1, 1, 1, "Z0H-", exe_inc_c},
			{ 0x0D, "DEC C"		, 1, 1, 1, "Z1H-", exe_dec_c},
			{ 0x0E, "LD C,u8"	, 2, 2, 2, "----", exe_ld_c_u8},
			{ 0x0F, "RRCA"		, 1, 1, 1, "000C"},
			{ 0x10, "STOP"		, 2, 1, 1, "----"},
			{ 0x11, "LD DE,u16"	, 3, 3, 3, "----", exe_ld_de_u16},
			{ 0x12, "LD (DE),A"	, 1, 2, 2, "----"},
			{ 0x13, "INC DE"	, 1, 2, 2, "----", exe_inc_de},
			{ 0x14, "INC D"		, 1, 1, 1, "Z0H-", exe_inc_d},
			{ 0x15, "DEC D"		, 1, 1, 1, "Z1H-", exe_dec_d},
			{ 0x16, "LD D,u8"	, 2, 2, 2, "----", exe_ld_d_u8},
			{ 0x17, "RLA"		, 1, 1, 1, "000C"},
			{ 0x18, "JR i8"		, 2, 3, 3, "----"},
			{ 0x19, "ADD HL,DE"	, 1, 2, 2, "-0HC"},
			{ 0x1A, "LD A,(DE)"	, 1, 2, 2, "----"},
			{ 0x1B, "DEC DE"	, 1, 2, 2, "----", exe_dec_de},
			{ 0x1C, "INC E"		, 1, 1, 1, "Z0H-", exe_inc_e},
			{ 0x1D, "DEC E"		, 1, 1, 1, "Z1H-", exe_dec_e},
			{ 0x1E, "LD E,u8"	, 2, 2, 2, "----", exe_ld_e_u8},
			{ 0x1F, "RRA"		, 1, 1, 1, "000C"},
			{ 0x20, "JR NZ,i8"	, 2, 2, 3, "----"},
			{ 0x21, "LD HL,u16"	, 3, 3, 3, "----", exe_ld_hl_u16},
			{ 0x22, "LD (HL+),A", 1, 2, 2, "----"},
			{ 0x23, "INC HL"	, 1, 2, 2, "----", exe_inc_hl},
			{ 0x24, "INC H"		, 1, 1, 1, "Z0H-", exe_inc_h},
			{ 0x25, "DEC H"		, 1, 1, 1, "Z1H-", exe_dec_h},
			{ 0x26, "LD H,u8"	, 2, 2, 2, "----", exe_ld_h_u8},
			{ 0x27, "DAA"		, 1, 1, 1, "Z-0C"},
			{ 0x28, "JR Z,i8"	, 2, 2, 3, "----"},
			{ 0x29, "ADD HL,HL"	, 1, 2, 2, "-0HC"},
			{ 0x2A, "LD A,(HL+)", 1, 2, 2, "----"},
			{ 0x2B, "DEC HL"	, 1, 2, 2, "----", exe_dec_hl},
			{ 0x2C, "INC L"		, 1, 1, 1, "Z0H-", exe_inc_l},
			{ 0x2D, "DEC L"		, 1, 1, 1, "Z1H-", exe_dec_l},
			{ 0x2E, "LD L,u8"	, 2, 2, 2, "----", exe_ld_l_u8},
			{ 0x2F, "CPL"		, 1, 1, 1, "-11-"},
			{ 0x30, "JR NC,i8"	, 2, 2, 3, "----"},
			{ 0x31, "LD SP,u16"	, 3, 3, 3, "----", exe_ld_sp_u16},
			{ 0x32, "LD (HL-),A", 1, 2, 2, "----", exe_ldd_hl_a},
			{ 0x33, "INC SP"	, 1, 2, 2, "----", exe_inc_sp},
			{ 0x34, "INC (HL)"	, 1, 3, 3, "Z0H-"},
			{ 0x35, "DEC (HL)"	, 1, 3, 3, "Z1H-"},
			{ 0x36, "LD (HL),u8", 2, 3, 3, "----"},
			{ 0x37, "SCF"		, 1, 1, 1, "-001"},
			{ 0x38, "JR C,i8"	, 2, 2, 3, "----"},
			{ 0x39, "ADD HL,SP"	, 1, 2, 2, "-0HC"},
			{ 0x3A, "LD A,(HL-)", 1, 2, 2, "----"},
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
			{ 0x70, "LD (HL),B"	, 1, 2, 2, "----"},
			{ 0x71, "LD (HL),C"	, 1, 2, 2, "----"},
			{ 0x72, "LD (HL),D"	, 1, 2, 2, "----"},
			{ 0x73, "LD (HL),E"	, 1, 2, 2, "----"},
			{ 0x74, "LD (HL),H"	, 1, 2, 2, "----"},
			{ 0x75, "LD (HL),L"	, 1, 2, 2, "----"},
			{ 0x76, "HALT"		, 1, 1, 1, "----"},
			{ 0x77, "LD (HL),A"	, 1, 2, 2, "----"},
			{ 0x78, "LD A,B"	, 1, 1, 1, "----", exe_ld_a_b },
			{ 0x79, "LD A,C"	, 1, 1, 1, "----", exe_ld_a_c },
			{ 0x7A, "LD A,D"	, 1, 1, 1, "----", exe_ld_a_d },
			{ 0x7B, "LD A,E"	, 1, 1, 1, "----", exe_ld_a_e },
			{ 0x7C, "LD A,H"	, 1, 1, 1, "----", exe_ld_a_h },
			{ 0x7D, "LD A,L"	, 1, 1, 1, "----", exe_ld_a_l },
			{ 0x7E, "LD A,(HL)"	, 1, 2, 2, "----", exe_ld_a_addr_hl },
			{ 0x7F, "LD A,A"	, 1, 1, 1, "----", exe_nop},
			{ 0x80, "ADD A,B"	, 1, 1, 1, "Z0HC"},
			{ 0x81, "ADD A,C"	, 1, 1, 1, "Z0HC"},
			{ 0x82, "ADD A,D"	, 1, 1, 1, "Z0HC"},
			{ 0x83, "ADD A,E"	, 1, 1, 1, "Z0HC"},
			{ 0x84, "ADD A,H"	, 1, 1, 1, "Z0HC"},
			{ 0x85, "ADD A,L"	, 1, 1, 1, "Z0HC"},
			{ 0x86, "ADD A,(HL)", 1, 2, 2, "Z0HC"},
			{ 0x87, "ADD A,A"	, 1, 1, 1, "Z0HC"},
			{ 0x88, "ADC A,B"	, 1, 1, 1, "Z0HC"},
			{ 0x89, "ADC A,C"	, 1, 1, 1, "Z0HC"},
			{ 0x8A, "ADC A,D"	, 1, 1, 1, "Z0HC"},
			{ 0x8B, "ADC A,E"	, 1, 1, 1, "Z0HC"},
			{ 0x8C, "ADC A,H"	, 1, 1, 1, "Z0HC"},
			{ 0x8D, "ADC A,L"	, 1, 1, 1, "Z0HC"},
			{ 0x8E, "ADC A,(HL)", 1, 2, 2, "Z0HC"},
			{ 0x8F, "ADC A,A"	, 1, 1, 1, "Z0HC"},
			{ 0x90, "SUB A,B"	, 1, 1, 1, "Z1HC"},
			{ 0x91, "SUB A,C"	, 1, 1, 1, "Z1HC"},
			{ 0x92, "SUB A,D"	, 1, 1, 1, "Z1HC"},
			{ 0x93, "SUB A,E"	, 1, 1, 1, "Z1HC"},
			{ 0x94, "SUB A,H"	, 1, 1, 1, "Z1HC"},
			{ 0x95, "SUB A,L"	, 1, 1, 1, "Z1HC"},
			{ 0x96, "SUB A,(HL)", 1, 2, 2, "Z1HC"},
			{ 0x97, "SUB A,A"	, 1, 1, 1, "Z1HC"},
			{ 0x98, "SBC A,B"	, 1, 1, 1, "Z1HC"},
			{ 0x99, "SBC A,C"	, 1, 1, 1, "Z1HC"},
			{ 0x9A, "SBC A,D"	, 1, 1, 1, "Z1HC"},
			{ 0x9B, "SBC A,E"	, 1, 1, 1, "Z1HC"},
			{ 0x9C, "SBC A,H"	, 1, 1, 1, "Z1HC"},
			{ 0x9D, "SBC A,L"	, 1, 1, 1, "Z1HC"},
			{ 0x9E, "SBC A,(HL)", 1, 2, 2, "Z1HC"},
			{ 0x9F, "SBC A,A"	, 1, 1, 1, "Z1HC"},
			{ 0xA0, "AND A,B"	, 1, 1, 1, "Z010"},
			{ 0xA1, "AND A,C"	, 1, 1, 1, "Z010"},
			{ 0xA2, "AND A,D"	, 1, 1, 1, "Z010"},
			{ 0xA3, "AND A,E"	, 1, 1, 1, "Z010"},
			{ 0xA4, "AND A,H"	, 1, 1, 1, "Z010"},
			{ 0xA5, "AND A,L"	, 1, 1, 1, "Z010"},
			{ 0xA6, "AND A,(HL)", 1, 2, 2, "Z010"},
			{ 0xA7, "AND A,A"	, 1, 1, 1, "Z010"},
			{ 0xA8, "XOR A,B"	, 1, 1, 1, "Z000", exe_xor_a_b },
			{ 0xA9, "XOR A,C"	, 1, 1, 1, "Z000", exe_xor_a_c },
			{ 0xAA, "XOR A,D"	, 1, 1, 1, "Z000", exe_xor_a_d },
			{ 0xAB, "XOR A,E"	, 1, 1, 1, "Z000", exe_xor_a_e },
			{ 0xAC, "XOR A,H"	, 1, 1, 1, "Z000", exe_xor_a_h },
			{ 0xAD, "XOR A,L"	, 1, 1, 1, "Z000", exe_xor_a_l },
			{ 0xAE, "XOR A,(HL)", 1, 2, 2, "Z000", exe_xor_a_addr_hl },
			{ 0xAF, "XOR A,A"	, 1, 1, 1, "Z000", exe_xor_a_a },
			{ 0xB0, "OR A,B"	, 1, 1, 1, "Z000"},
			{ 0xB1, "OR A,C"	, 1, 1, 1, "Z000"},
			{ 0xB2, "OR A,D"	, 1, 1, 1, "Z000"},
			{ 0xB3, "OR A,E"	, 1, 1, 1, "Z000"},
			{ 0xB4, "OR A,H"	, 1, 1, 1, "Z000"},
			{ 0xB5, "OR A,L"	, 1, 1, 1, "Z000"},
			{ 0xB6, "OR A,(HL)"	, 1, 2, 2, "Z000"},
			{ 0xB7, "OR A,A"	, 1, 1, 1, "Z000"},
			{ 0xB8, "CP A,B"	, 1, 1, 1, "Z1HC"},
			{ 0xB9, "CP A,C"	, 1, 1, 1, "Z1HC"},
			{ 0xBA, "CP A,D"	, 1, 1, 1, "Z1HC"},
			{ 0xBB, "CP A,E"	, 1, 1, 1, "Z1HC"},
			{ 0xBC, "CP A,H"	, 1, 1, 1, "Z1HC"},
			{ 0xBD, "CP A,L"	, 1, 1, 1, "Z1HC"},
			{ 0xBE, "CP A,(HL)"	, 1, 2, 2, "Z1HC"},
			{ 0xBF, "CP A,A"	, 1, 1, 1, "Z1HC"},
			{ 0xC0, "RET NZ"	, 1, 2, 5, "----"},
			{ 0xC1, "POP BC"	, 1, 3, 3, "----"},
			{ 0xC2, "JP NZ,u16"	, 3, 3, 4, "----"},
			{ 0xC3, "JP u16"	, 3, 4, 4, "----", exe_jp_addr_pc},
			{ 0xC4, "CALL NZ,u16",3, 3, 6, "----"},
			{ 0xC5, "PUSH BC"	, 1, 4, 4, "----"},
			{ 0xC6, "ADD A,u8"	, 2, 2, 2, "Z0HC"},
			{ 0xC7, "RST 00h"	, 1, 4, 4, "----"},
			{ 0xC8, "RET Z"		, 1, 2, 5, "----"},
			{ 0xC9, "RET"		, 1, 4, 4, "----"},
			{ 0xCA, "JP Z,u16"	, 3, 3, 4, "----"},
			{ 0xCB, "PREFIX CB"	, 1, 1, 1, "----"},
			{ 0xCC, "CALL Z,u16", 3, 3, 6, "----"},
			{ 0xCD, "CALL u16"	, 3, 6, 6, "----"},
			{ 0xCE, "ADC A,u8"	, 2, 2, 2, "Z0HC"},
			{ 0xCF, "RST 08h"	, 1, 4, 4, "----"},
			{ 0xD0, "RET NC"	, 1, 2, 5, "----"},
			{ 0xD1, "POP DE"	, 1, 3, 3, "----"},
			{ 0xD2, "JP NC,u16"	, 3, 3, 4, "----"},
			{ 0xD3, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xD4, "CALL NC,u16",3, 3, 6, "----"},
			{ 0xD5, "PUSH DE"	, 1, 4, 4, "----"},
			{ 0xD6, "SUB A,u8"	, 2, 2, 2, "Z1HC"},
			{ 0xD7, "RST 10h"	, 1, 4, 4, "----"},
			{ 0xD8, "RET C"		, 1, 2, 5, "----"},
			{ 0xD9, "RETI"		, 1, 4, 4, "----"},
			{ 0xDA, "JP C,u16"	, 3, 3, 4, "----"},
			{ 0xDB, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xDC, "CALL C,u16", 3, 3, 6, "----"},
			{ 0xDD, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xDE, "SBC A,u8"	, 2, 2, 2, "Z1HC"},
			{ 0xDF, "RST 18h"	, 1, 4, 4, "----"},
			{ 0xE0, "LD (FF00+u8),A",2,3,3,"----"},
			{ 0xE1, "POP HL"	, 1, 3, 3, "----"},
			{ 0xE2, "LD (FF00+C),A",1,2,2, "----"},
			{ 0xE3, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xE4, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xE5, "PUSH HL"	, 1, 4, 4, "----"},
			{ 0xE6, "AND A,u8"	, 2, 2, 2, "Z010"},
			{ 0xE7, "RST 20h"	, 1, 4, 4, "----"},
			{ 0xE8, "ADD SP,i8"	, 2, 4, 4, "00HC"},
			{ 0xE9, "JP HL"		, 1, 1, 1, "----"},
			{ 0xEA, "LD (u16),A", 3, 4, 4, "----"},
			{ 0xEB, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xEC, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xED, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xEE, "XOR A,u8"	, 2, 2, 2, "Z000"},
			{ 0xEF, "RST 28h"	, 1, 4, 4, "----"},
			{ 0xF0, "LD A,(FF00+u8)",2,3,3,"----"},
			{ 0xF1, "POP AF"	, 1, 3, 3, "ZNHC"},
			{ 0xF2, "LD A,(FF00+C)",1,2,2, "----"},
			{ 0xF3, "DI"		, 1, 1, 1, "----"},
			{ 0xF4, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xF5, "PUSH AF"	, 1, 4, 4, "----"},
			{ 0xF6, "OR A,u8"	, 2, 2, 2, "Z000"},
			{ 0xF7, "RST 30h"	, 1, 4, 4, "----"},
			{ 0xF8, "LD HL,SP+i8",2, 3, 3, "00HC"},
			{ 0xF9, "LD SP,HL"	, 1, 2, 2, "----"},
			{ 0xFA, "LD A,(u16)", 3, 4, 4, "----"},
			{ 0xFB, "EI"		, 1, 1, 1, "----"},
			{ 0xFC, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xFD, "UNUSED"	, 0, 0, 0, "----"},
			{ 0xFE, "CP A,u8"	, 2, 2, 2, "Z1HC"},
			{ 0xFF, "RST 38h"	, 1, 4, 4, "----"}
};