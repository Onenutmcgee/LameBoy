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

	void DumpToCout();
	std::string Title();
	int CartType();

	std::vector<BYTE> *CartridgeMemory;
	bool GamePakIsLoaded;

private:
	BYTE* _cartMemArray;
};

