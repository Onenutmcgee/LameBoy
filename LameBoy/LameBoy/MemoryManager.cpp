#include "MemoryManager.h"

MemoryManager::MemoryManager(GamePak* cart)
{
	_cart = cart;

	_vram = new BYTE[0x2000];
	_ram = new BYTE[0x2000];
	_upperMemory = new BYTE[0x200];

	Initialize();
}

MemoryManager::~MemoryManager()
{
	delete _vram;
	delete _ram;
	delete _upperMemory;
}

void MemoryManager::Initialize()
{
	memset(_vram, 0, 0x2000);
	memset(_ram, 0, 0x2000);
	memset(_upperMemory, 0, 0x200);

	_upperMemory[0xFF10 - UPPER_MEM_OFFSET] = 0x80;
	_upperMemory[0xFF11 - UPPER_MEM_OFFSET] = 0xBF;
	_upperMemory[0xFF12 - UPPER_MEM_OFFSET] = 0xF3;
	_upperMemory[0xFF14 - UPPER_MEM_OFFSET] = 0xBF;
	_upperMemory[0xFF16 - UPPER_MEM_OFFSET] = 0x3F;
	_upperMemory[0xFF19 - UPPER_MEM_OFFSET] = 0xBF;
	_upperMemory[0xFF1A - UPPER_MEM_OFFSET] = 0x7F;
	_upperMemory[0xFF1B - UPPER_MEM_OFFSET] = 0xFF;
	_upperMemory[0xFF1C - UPPER_MEM_OFFSET] = 0x9F;
	_upperMemory[0xFF1E - UPPER_MEM_OFFSET] = 0xBF;
	_upperMemory[0xFF20 - UPPER_MEM_OFFSET] = 0xFF;
	_upperMemory[0xFF23 - UPPER_MEM_OFFSET] = 0xBF;
	_upperMemory[0xFF24 - UPPER_MEM_OFFSET] = 0x77;
	_upperMemory[0xFF25 - UPPER_MEM_OFFSET] = 0xF3;
	_upperMemory[0xFF26 - UPPER_MEM_OFFSET] = 0xF1; // This is for GB, SGB uses 0xF0
	_upperMemory[0xFF40 - UPPER_MEM_OFFSET] = 0x91;
	_upperMemory[0xFF47 - UPPER_MEM_OFFSET] = 0xFC;
	_upperMemory[0xFF48 - UPPER_MEM_OFFSET] = 0xFF;
	_upperMemory[0xFF49 - UPPER_MEM_OFFSET] = 0xFF;
}

BYTE MemoryManager::ReadByte(WORD address)
{
	if (address < VRAM_OFFSET) // This is ROM data, read that from the cart
	{
		return _cart->ReadByte(address);
	}
	else if (address < CART_RAM_OFFSET) // This is VRAM data
	{
		return _vram[address - VRAM_OFFSET];
	}
	else if (address < RAM_OFFSET) // This is cart RAM, read from cart
	{
		return _cart->ReadByte(address);
	}
	else if (address < RAM_ECHO_OFFSET) // This is internal RAM
	{
		return _ram[address - RAM_OFFSET];
	}
	else if (address < UPPER_MEM_OFFSET) // This is in the echo
	{
		return _ram[address - RAM_ECHO_OFFSET];
	}
	// if none of that, then this is in upper memory
	// This will need to be tweaked for I/O, but for now, we'll just dump it all here
	return _upperMemory[address - UPPER_MEM_OFFSET];
}

void MemoryManager::WriteByte(WORD address, BYTE value)
{
	// There is some switching that needs to be done here depending on the address
	// TODO: Handle special ROM writes and RAM protection

	if (address < CART_RAM_OFFSET) // this is a write to VRAM
	{
		_vram[address - VRAM_OFFSET] = value;
	}
	if (address < RAM_OFFSET) // This is a write to the cart RAM
	{
		_cart->WriteByte(address, value);
	}
	else if (address < RAM_ECHO_OFFSET) // this is a write to internal RAM
	{
		_ram[address - RAM_OFFSET] = value;
	}
	else if (address < UPPER_MEM_OFFSET) // this is a write to the echo
	{
		_ram[address - RAM_ECHO_OFFSET] = value;
	}
	else // this is a write to the upper memory
	{
		_upperMemory[address - UPPER_MEM_OFFSET] = value;
	}
}
