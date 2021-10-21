#include "GamePak.h"

#include <fstream>
#include <sys/stat.h>
#include <sstream>

// TODO: Remove this, we should not use cout here
#include <iostream>
#include <iomanip>

int GetFileSize(const std::string&);

GamePak::GamePak()
{
	CartridgeMemory = NULL;
	_cartMemArray = NULL;
	GamePakIsLoaded = false;
}

GamePak::GamePak(const std::string& rom)
{
	CartridgeMemory = NULL;
	_cartMemArray = NULL;
	GamePakIsLoaded = false;
	Load(rom);
}

GamePak::~GamePak()
{
	if (this->GamePakIsLoaded)
		delete CartridgeMemory;
}

void GamePak::Load(const std::string &rom)
{
	if (this->GamePakIsLoaded)
	{
		delete CartridgeMemory;
		this->GamePakIsLoaded = false;
	}

	int fileSize = GetFileSize(rom);
	CartridgeMemory = new std::vector<BYTE>();
	CartridgeMemory->resize(fileSize);

	std::ifstream fl;
	fl.open(rom, std::fstream::binary);
	
	fl.read((char*)CartridgeMemory->data(), CartridgeMemory->size());

	fl.close();

	_cartMemArray = CartridgeMemory->data();
	this->GamePakIsLoaded = true;
}

std::string GamePak::Title()
{
	if (!this->GamePakIsLoaded)
		return "No GamePak is loaded.";

	std::string str((char*)&_cartMemArray[0x134], 16);
	return str;
}

int GamePak::CartType()
{
	return _cartMemArray[0x0147];
}

// TODO: Change this to dump to a string
void GamePak::DumpToCout()
{
	if (!this->GamePakIsLoaded)
	{
		std::cout << "GamePak is not loaded.";
		return;
	}

	int count =0;

	for (unsigned int i = 0; i < CartridgeMemory->size(); i++)
	{
		if (count == 0)
			std::cout << "$" << std::setw(10) << std::setfill('0') << std::hex << i << ":";
		else if (count % 5 == 0)
			std::cout << "  ";

		std::cout << " " << std::setw(2) << std::setfill('0') << std::hex << +(*CartridgeMemory)[i];

		if (++count >= 20)
		{
			count = 0;
			std::cout << "\n";
		}
	}
}

int GetFileSize(const std::string& rom)
{
	std::ifstream in_file(rom, std::ios::binary);
	in_file.seekg(0, std::ios::end);
	return (int)in_file.tellg();
}