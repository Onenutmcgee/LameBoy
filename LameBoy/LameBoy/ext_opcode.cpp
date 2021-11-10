#include "opcode.h"
#include "CPU.h"

bool OPC::exe_swap_a(CPU* cp)
{
	return cp->swap(&cp->reg.a);
}

bool OPC::exe_swap_b(CPU* cp)
{
	return cp->swap(&cp->reg.b);
}

bool OPC::exe_swap_c(CPU* cp)
{
	return cp->swap(&cp->reg.c);
}

bool OPC::exe_swap_d(CPU* cp)
{
	return cp->swap(&cp->reg.d);
}

bool OPC::exe_swap_e(CPU* cp)
{
	return cp->swap(&cp->reg.e);
}

bool OPC::exe_swap_h(CPU* cp)
{
	return cp->swap(&cp->reg.h);
}

bool OPC::exe_swap_l(CPU* cp)
{
	return cp->swap(&cp->reg.l);
}

bool OPC::exe_swap_addr_hl(CPU* cp)
{
	return cp->swap_addr(cp->reg.hl);
}

// res 0
bool OPC::exe_res_0_a(CPU* cp)
{
	return cp->bit_res(0, &cp->reg.a);
}

bool OPC::exe_res_0_b(CPU* cp)
{
	return cp->bit_res(0, &cp->reg.b);
}

bool OPC::exe_res_0_c(CPU* cp)
{
	return cp->bit_res(0, &cp->reg.c);
}

bool OPC::exe_res_0_d(CPU* cp)
{
	return cp->bit_res(0, &cp->reg.d);
}

bool OPC::exe_res_0_e(CPU* cp)
{
	return cp->bit_res(0, &cp->reg.e);
}

bool OPC::exe_res_0_h(CPU* cp)
{
	return cp->bit_res(0, &cp->reg.h);
}

bool OPC::exe_res_0_l(CPU* cp)
{
	return cp->bit_res(0, &cp->reg.l);
}

bool OPC::exe_res_0_addr_hl(CPU* cp)
{
	return cp->bit_res(0, cp->reg.hl);
}

struct OPC::opcode OPC::ext_opcodes[256] = {
			{ 0x00, "RLC B"		, 2, 2, 2, "Z00C", NULL },
			{ 0x01, "RLC C"		, 2, 2, 2, "Z00C", NULL },
			{ 0x02, "RLC D"		, 2, 2, 2, "Z00C", NULL },
			{ 0x03, "RLC E"		, 2, 2, 2, "Z00C", NULL },
			{ 0x04, "RLC H"		, 2, 2, 2, "Z00C", NULL },
			{ 0x05, "RLC L"		, 2, 2, 2, "Z00C", NULL },
			{ 0x06, "RLC (HL)"	, 2, 4, 4, "Z00C", NULL },
			{ 0x07, "RLC A"		, 2, 2, 2, "Z00C", NULL },
			{ 0x08, "RRC B"		, 2, 2, 2, "Z00C", NULL },
			{ 0x09, "RRC C"		, 2, 2, 2, "Z00C", NULL },
			{ 0x0A, "RRC D"		, 2, 2, 2, "Z00C", NULL },
			{ 0x0B, "RRC E"		, 2, 2, 2, "Z00C", NULL },
			{ 0x0C, "RRC H"		, 2, 2, 2, "Z00C", NULL },
			{ 0x0D, "RRC L"		, 2, 2, 2, "Z00C", NULL },
			{ 0x0E, "RRC (HL)"	, 2, 4, 4, "Z00C", NULL },
			{ 0x0F, "RRC A"		, 2, 2, 2, "Z00C", NULL },
			{ 0x10, "RL B"		, 2, 2, 2, "Z00C", NULL },
			{ 0x11, "RL C"		, 2, 2, 2, "Z00C", NULL },
			{ 0x12, "RL D"		, 2, 2, 2, "Z00C", NULL },
			{ 0x13, "RL E"		, 2, 2, 2, "Z00C", NULL },
			{ 0x14, "RL H"		, 2, 2, 2, "Z00C", NULL },
			{ 0x15, "RL L"		, 2, 2, 2, "Z00C", NULL },
			{ 0x16, "RL (HL)"	, 2, 4, 4, "Z00C", NULL },
			{ 0x17, "RL A"		, 2, 2, 2, "Z00C", NULL },
			{ 0x18, "RR B"		, 2, 2, 2, "Z00C", NULL },
			{ 0x19, "RR C"		, 2, 2, 2, "Z00C", NULL },
			{ 0x1A, "RR D"		, 2, 2, 2, "Z00C", NULL },
			{ 0x1B, "RR E"		, 2, 2, 2, "Z00C", NULL },
			{ 0x1C, "RR H"		, 2, 2, 2, "Z00C", NULL },
			{ 0x1D, "RR L"		, 2, 2, 2, "Z00C", NULL },
			{ 0x1E, "RR (HL)"	, 2, 4, 4, "Z00C", NULL },
			{ 0x1F, "RR A"		, 2, 2, 2, "Z00C", NULL },
			{ 0x20, "SLA B"		, 2, 2, 2, "Z00C", NULL },
			{ 0x21, "SLA C"		, 2, 2, 2, "Z00C", NULL },
			{ 0x22, "SLA D"		, 2, 2, 2, "Z00C", NULL },
			{ 0x23, "SLA E"		, 2, 2, 2, "Z00C", NULL },
			{ 0x24, "SLA H"		, 2, 2, 2, "Z00C", NULL },
			{ 0x25, "SLA L"		, 2, 2, 2, "Z00C", NULL },
			{ 0x26, "SLA (HL)"	, 2, 4, 4, "Z00C", NULL },
			{ 0x27, "SLA A"		, 2, 2, 2, "Z00C", NULL },
			{ 0x28, "SRA B"		, 2, 2, 2, "Z00C", NULL },
			{ 0x29, "SRA C"		, 2, 2, 2, "Z00C", NULL },
			{ 0x2A, "SRA D"		, 2, 2, 2, "Z00C", NULL },
			{ 0x2B, "SRA E"		, 2, 2, 2, "Z00C", NULL },
			{ 0x2C, "SRA H"		, 2, 2, 2, "Z00C", NULL },
			{ 0x2D, "SRA L"		, 2, 2, 2, "Z00C", NULL },
			{ 0x2E, "SRA (HL)"	, 2, 4, 4, "Z00C", NULL },
			{ 0x2F, "SRA A"		, 2, 2, 2, "Z00C", NULL },
			{ 0x30, "SWAP B"	, 2, 2, 2, "Z000", exe_swap_b },
			{ 0x31, "SWAP C"	, 2, 2, 2, "Z000", exe_swap_c },
			{ 0x32, "SWAP D"	, 2, 2, 2, "Z000", exe_swap_d },
			{ 0x33, "SWAP E"	, 2, 2, 2, "Z000", exe_swap_e },
			{ 0x34, "SWAP H"	, 2, 2, 2, "Z000", exe_swap_h },
			{ 0x35, "SWAP L"	, 2, 2, 2, "Z000", exe_swap_l },
			{ 0x36, "SWAP (HL)"	, 2, 4, 4, "Z000", exe_swap_addr_hl },
			{ 0x37, "SWAP A"	, 2, 2, 2, "Z000", exe_swap_a },
			{ 0x38, "SRL B"		, 2, 2, 2, "Z00C", NULL },
			{ 0x39, "SRL C"		, 2, 2, 2, "Z00C", NULL },
			{ 0x3A, "SRL D"		, 2, 2, 2, "Z00C", NULL },
			{ 0x3B, "SRL E"		, 2, 2, 2, "Z00C", NULL },
			{ 0x3C, "SRL H"		, 2, 2, 2, "Z00C", NULL },
			{ 0x3D, "SRL L"		, 2, 2, 2, "Z00C", NULL },
			{ 0x3E, "SRL (HL)"	, 2, 4, 4, "Z00C", NULL },
			{ 0x3F, "SRL A"		, 2, 2, 2, "Z00C", NULL },
			{ 0x40, "BIT 0,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x41, "BIT 0,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x42, "BIT 0,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x43, "BIT 0,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x44, "BIT 0,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x45, "BIT 0,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x46, "BIT 0,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x47, "BIT 0,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x48, "BIT 1,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x49, "BIT 1,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x4A, "BIT 1,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x4B, "BIT 1,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x4C, "BIT 1,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x4D, "BIT 1,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x4E, "BIT 1,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x4F, "BIT 1,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x50, "BIT 2,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x51, "BIT 2,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x52, "BIT 2,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x53, "BIT 2,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x54, "BIT 2,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x55, "BIT 2,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x56, "BIT 2,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x57, "BIT 2,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x58, "BIT 3,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x59, "BIT 3,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x5A, "BIT 3,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x5B, "BIT 3,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x5C, "BIT 3,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x5D, "BIT 3,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x5E, "BIT 3,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x5F, "BIT 3,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x60, "BIT 4,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x61, "BIT 4,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x62, "BIT 4,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x63, "BIT 4,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x64, "BIT 4,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x65, "BIT 4,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x66, "BIT 4,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x67, "BIT 4,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x68, "BIT 5,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x69, "BIT 5,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x6A, "BIT 5,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x6B, "BIT 5,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x6C, "BIT 5,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x6D, "BIT 5,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x6E, "BIT 5,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x6F, "BIT 5,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x70, "BIT 6,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x71, "BIT 6,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x72, "BIT 6,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x73, "BIT 6,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x74, "BIT 6,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x75, "BIT 6,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x76, "BIT 6,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x77, "BIT 6,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x78, "BIT 7,B"	, 2, 2, 2, "Z01-", NULL },
			{ 0x79, "BIT 7,C"	, 2, 2, 2, "Z01-", NULL },
			{ 0x7A, "BIT 7,D"	, 2, 2, 2, "Z01-", NULL },
			{ 0x7B, "BIT 7,E"	, 2, 2, 2, "Z01-", NULL },
			{ 0x7C, "BIT 7,H"	, 2, 2, 2, "Z01-", NULL },
			{ 0x7D, "BIT 7,L"	, 2, 2, 2, "Z01-", NULL },
			{ 0x7E, "BIT 7,(HL)", 2, 3, 3, "Z01-", NULL },
			{ 0x7F, "BIT 7,A"	, 2, 2, 2, "Z01-", NULL },
			{ 0x80, "RES 0,B"	, 2, 2, 2, "----", exe_res_0_b },
			{ 0x81, "RES 0,C"	, 2, 2, 2, "----", exe_res_0_c },
			{ 0x82, "RES 0,D"	, 2, 2, 2, "----", exe_res_0_d },
			{ 0x83, "RES 0,E"	, 2, 2, 2, "----", exe_res_0_e },
			{ 0x84, "RES 0,H"	, 2, 2, 2, "----", exe_res_0_h },
			{ 0x85, "RES 0,L"	, 2, 2, 2, "----", exe_res_0_l },
			{ 0x86, "RES 0,(HL)", 2, 4, 4, "----", exe_res_0_addr_hl },
			{ 0x87, "RES 0,A"	, 2, 2, 2, "----", exe_res_0_a },
			{ 0x88, "RES 1,B"	, 2, 2, 2, "----", NULL },
			{ 0x89, "RES 1,C"	, 2, 2, 2, "----", NULL },
			{ 0x8A, "RES 1,D"	, 2, 2, 2, "----", NULL },
			{ 0x8B, "RES 1,E"	, 2, 2, 2, "----", NULL },
			{ 0x8C, "RES 1,H"	, 2, 2, 2, "----", NULL },
			{ 0x8D, "RES 1,L"	, 2, 2, 2, "----", NULL },
			{ 0x8E, "RES 1,(HL)", 2, 4, 4, "----", NULL },
			{ 0x8F, "RES 1,A"	, 2, 2, 2, "----", NULL },
			{ 0x90, "RES 2,B"	, 2, 2, 2, "----", NULL },
			{ 0x91, "RES 2,C"	, 2, 2, 2, "----", NULL },
			{ 0x92, "RES 2,D"	, 2, 2, 2, "----", NULL },
			{ 0x93, "RES 2,E"	, 2, 2, 2, "----", NULL },
			{ 0x94, "RES 2,H"	, 2, 2, 2, "----", NULL },
			{ 0x95, "RES 2,L"	, 2, 2, 2, "----", NULL },
			{ 0x96, "RES 2,(HL)", 2, 4, 4, "----", NULL },
			{ 0x97, "RES 2,A"	, 2, 2, 2, "----", NULL },
			{ 0x98, "RES 3,B"	, 2, 2, 2, "----", NULL },
			{ 0x99, "RES 3,C"	, 2, 2, 2, "----", NULL },
			{ 0x9A, "RES 3,D"	, 2, 2, 2, "----", NULL },
			{ 0x9B, "RES 3,E"	, 2, 2, 2, "----", NULL },
			{ 0x9C, "RES 3,H"	, 2, 2, 2, "----", NULL },
			{ 0x9D, "RES 3,L"	, 2, 2, 2, "----", NULL },
			{ 0x9E, "RES 3,(HL)", 2, 4, 4, "----", NULL },
			{ 0x9F, "RES 3,A"	, 2, 2, 2, "----", NULL },
			{ 0xA0, "RES 4,B"	, 2, 2, 2, "----", NULL },
			{ 0xA1, "RES 4,C"	, 2, 2, 2, "----", NULL },
			{ 0xA2, "RES 4,D"	, 2, 2, 2, "----", NULL },
			{ 0xA3, "RES 4,E"	, 2, 2, 2, "----", NULL },
			{ 0xA4, "RES 4,H"	, 2, 2, 2, "----", NULL },
			{ 0xA5, "RES 4,L"	, 2, 2, 2, "----", NULL },
			{ 0xA6, "RES 4,(HL)", 2, 4, 4, "----", NULL },
			{ 0xA7, "RES 4,A"	, 2, 2, 2, "----", NULL },
			{ 0xA8, "RES 5,B"	, 2, 2, 2, "----", NULL },
			{ 0xA9, "RES 5,C"	, 2, 2, 2, "----", NULL },
			{ 0xAA, "RES 5,D"	, 2, 2, 2, "----", NULL },
			{ 0xAB, "RES 5,E"	, 2, 2, 2, "----", NULL },
			{ 0xAC, "RES 5,H"	, 2, 2, 2, "----", NULL },
			{ 0xAD, "RES 5,L"	, 2, 2, 2, "----", NULL },
			{ 0xAE, "RES 5,(HL)", 2, 4, 4, "----", NULL },
			{ 0xAF, "RES 5,A"	, 2, 2, 2, "----", NULL },
			{ 0xB0, "RES 6,B"	, 2, 2, 2, "----", NULL },
			{ 0xB1, "RES 6,C"	, 2, 2, 2, "----", NULL },
			{ 0xB2, "RES 6,D"	, 2, 2, 2, "----", NULL },
			{ 0xB3, "RES 6,E"	, 2, 2, 2, "----", NULL },
			{ 0xB4, "RES 6,H"	, 2, 2, 2, "----", NULL },
			{ 0xB5, "RES 6,L"	, 2, 2, 2, "----", NULL },
			{ 0xB6, "RES 6,(HL)", 2, 4, 4, "----", NULL },
			{ 0xB7, "RES 6,A"	, 2, 2, 2, "----", NULL },
			{ 0xB8, "RES 7,B"	, 2, 2, 2, "----", NULL },
			{ 0xB9, "RES 7,C"	, 2, 2, 2, "----", NULL },
			{ 0xBA, "RES 7,D"	, 2, 2, 2, "----", NULL },
			{ 0xBB, "RES 7,E"	, 2, 2, 2, "----", NULL },
			{ 0xBC, "RES 7,H"	, 2, 2, 2, "----", NULL },
			{ 0xBD, "RES 7,L"	, 2, 2, 2, "----", NULL },
			{ 0xBE, "RES 7,(HL)", 2, 4, 4, "----", NULL },
			{ 0xBF, "RES 7,A"	, 2, 2, 2, "----", NULL },
			{ 0xC0, "SET 0,B"	, 2, 2, 2, "----", NULL },
			{ 0xC1, "SET 0,C"	, 2, 2, 2, "----", NULL },
			{ 0xC2, "SET 0,D"	, 2, 2, 2, "----", NULL },
			{ 0xC3, "SET 0,E"	, 2, 2, 2, "----", NULL },
			{ 0xC4, "SET 0,H"	, 2, 2, 2, "----", NULL },
			{ 0xC5, "SET 0,L"	, 2, 2, 2, "----", NULL },
			{ 0xC6, "SET 0,(HL)", 2, 4, 4, "----", NULL },
			{ 0xC7, "SET 0,A"	, 2, 2, 2, "----", NULL },
			{ 0xC8, "SET 1,B"	, 2, 2, 2, "----", NULL },
			{ 0xC9, "SET 1,C"	, 2, 2, 2, "----", NULL },
			{ 0xCA, "SET 1,D"	, 2, 2, 2, "----", NULL },
			{ 0xCB, "SET 1,E"	, 2, 2, 2, "----", NULL },
			{ 0xCC, "SET 1,H"	, 2, 2, 2, "----", NULL },
			{ 0xCD, "SET 1,L"	, 2, 2, 2, "----", NULL },
			{ 0xCE, "SET 1,(HL)", 2, 4, 4, "----", NULL },
			{ 0xCF, "SET 1,A"	, 2, 2, 2, "----", NULL },
			{ 0xD0, "SET 2,B"	, 2, 2, 2, "----", NULL },
			{ 0xD1, "SET 2,C"	, 2, 2, 2, "----", NULL },
			{ 0xD2, "SET 2,D"	, 2, 2, 2, "----", NULL },
			{ 0xD3, "SET 2,E"	, 2, 2, 2, "----", NULL },
			{ 0xD4, "SET 2,H"	, 2, 2, 2, "----", NULL },
			{ 0xD5, "SET 2,L"	, 2, 2, 2, "----", NULL },
			{ 0xD6, "SET 2,(HL)", 2, 4, 4, "----", NULL },
			{ 0xD7, "SET 2,A"	, 2, 2, 2, "----", NULL },
			{ 0xD8, "SET 3,B"	, 2, 2, 2, "----", NULL },
			{ 0xD9, "SET 3,C"	, 2, 2, 2, "----", NULL },
			{ 0xDA, "SET 3,D"	, 2, 2, 2, "----", NULL },
			{ 0xDB, "SET 3,E"	, 2, 2, 2, "----", NULL },
			{ 0xDC, "SET 3,H"	, 2, 2, 2, "----", NULL },
			{ 0xDD, "SET 3,L"	, 2, 2, 2, "----", NULL },
			{ 0xDE, "SET 3,(HL)", 2, 4, 4, "----", NULL },
			{ 0xDF, "SET 3,A"	, 2, 2, 2, "----", NULL },
			{ 0xE0, "SET 4,B"	, 2, 2, 2, "----", NULL },
			{ 0xE1, "SET 4,C"	, 2, 2, 2, "----", NULL },
			{ 0xE2, "SET 4,D"	, 2, 2, 2, "----", NULL },
			{ 0xE3, "SET 4,E"	, 2, 2, 2, "----", NULL },
			{ 0xE4, "SET 4,H"	, 2, 2, 2, "----", NULL },
			{ 0xE5, "SET 4,L"	, 2, 2, 2, "----", NULL },
			{ 0xE6, "SET 4,(HL)", 2, 4, 4, "----", NULL },
			{ 0xE7, "SET 4,A"	, 2, 2, 2, "----", NULL },
			{ 0xE8, "SET 5,B"	, 2, 2, 2, "----", NULL },
			{ 0xE9, "SET 5,C"	, 2, 2, 2, "----", NULL },
			{ 0xEA, "SET 5,D"	, 2, 2, 2, "----", NULL },
			{ 0xEB, "SET 5,E"	, 2, 2, 2, "----", NULL },
			{ 0xEC, "SET 5,H"	, 2, 2, 2, "----", NULL },
			{ 0xED, "SET 5,L"	, 2, 2, 2, "----", NULL },
			{ 0xEE, "SET 5,(HL)", 2, 4, 4, "----", NULL },
			{ 0xEF, "SET 5,A"	, 2, 2, 2, "----", NULL },
			{ 0xF0, "SET 6,B"	, 2, 2, 2, "----", NULL },
			{ 0xF1, "SET 6,C"	, 2, 2, 2, "----", NULL },
			{ 0xF2, "SET 6,D"	, 2, 2, 2, "----", NULL },
			{ 0xF3, "SET 6,E"	, 2, 2, 2, "----", NULL },
			{ 0xF4, "SET 6,H"	, 2, 2, 2, "----", NULL },
			{ 0xF5, "SET 6,L"	, 2, 2, 2, "----", NULL },
			{ 0xF6, "SET 6,(HL)", 2, 4, 4, "----", NULL },
			{ 0xF7, "SET 6,A"	, 2, 2, 2, "----", NULL },
			{ 0xF8, "SET 7,B"	, 2, 2, 2, "----", NULL },
			{ 0xF9, "SET 7,C"	, 2, 2, 2, "----", NULL },
			{ 0xFA, "SET 7,D"	, 2, 2, 2, "----", NULL },
			{ 0xFB, "SET 7,E"	, 2, 2, 2, "----", NULL },
			{ 0xFC, "SET 7,H"	, 2, 2, 2, "----", NULL },
			{ 0xFD, "SET 7,L"	, 2, 2, 2, "----", NULL },
			{ 0xFE, "SET 7,(HL)", 2, 4, 4, "----", NULL },
			{ 0xFF, "SET 7,A"	, 2, 2, 2, "----", NULL }

};