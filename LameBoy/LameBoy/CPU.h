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
	bool jp_u16();

	// byte ALU
	bool xor_n(BYTE);

	// 16 bit loads
	bool ld_hl_u16();

private:
	void SetFlag(BYTE);

	MemoryManager* _mem;
	GamePak* _cart;

	
};

