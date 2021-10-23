#pragma once

#include "TypeDefs.h"
#include "GamePak.h"


class MemoryManager
{
public:
	MemoryManager(GamePak* cart);
	~MemoryManager();

	void Initialize();

	BYTE ReadByte(WORD);
	SIGNED_BYTE ReadSignedByte(WORD);
	WORD ReadWord(WORD);
	SIGNED_WORD ReadSignedWord(WORD);

	void WriteByte(WORD, BYTE);


private:
	const WORD VRAM_OFFSET		= 0x8000;
	const WORD CART_RAM_OFFSET	= 0xA000;
	const WORD RAM_OFFSET		= 0xC000;
	const WORD RAM_ECHO_OFFSET	= 0xE000;
	const WORD UPPER_MEM_OFFSET = 0xFE00;


	GamePak* _cart;
	BYTE* _vram;
	BYTE* _ram;
	BYTE* _upperMemory;
};

