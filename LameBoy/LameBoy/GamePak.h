#pragma once
#include <string>
#include <vector>
#include "TypeDefs.h"


// Class to represent the GB GamePak
class GamePak
{
public:
	// Default constructor
	GamePak();
	// Initializes GamePak and loads rom
	GamePak(const std::string& rom);

	~GamePak();

	// Method used to load the rom from the given path
	void Load(const std::string& rom);

	BYTE ReadByte(WORD address);
	void WriteByte(WORD address, BYTE value);

	void DumpToCout();
	std::string Title();
	int CartType();

	std::vector<BYTE> *CartridgeMemory;
	bool GamePakIsLoaded;

private:
	const WORD ROM_BANK_0_CUTOFF = 0x4000;
	const WORD ROM_BANK_SWITCH_CUTTOFF = 0x8000;
	const WORD RAM_BANK_OFFSET = 0xA000;

	BYTE* _cartMemArray;
	WORD _currentRomBank = 1;
};

