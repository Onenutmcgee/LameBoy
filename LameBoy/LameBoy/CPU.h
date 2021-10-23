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
	CPU(GamePak* cart);
	~CPU();

	Registers reg;

	void Initialize();
	void Reset();
	OPC::opcode ExecuteNextOpcode(BYTE*);
	OPC::opcode PeekNextOpcode();
	
	bool nop();

	// jumps
	bool jp_addr(WORD);

	// byte ALU
	bool xor_a_n(BYTE val);
	bool xor_a_addr(WORD);

	// 16 bit loads
	bool ld_hl_u16();

	// 8 bit loads
	bool ld_a_val(BYTE);
	bool ld_a_addr(WORD);
	bool ld_b_val(BYTE);
	bool ld_b_addr(WORD);


private:
	void SetFlag(BYTE);

	MemoryManager* _mem;
	GamePak* _cart;

	
};

