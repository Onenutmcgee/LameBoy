#pragma once
#include "MemoryManager.h"
#include "GamePak.h"
#include "Registers.h"
#include "TypeDefs.h"

class CPU
{
public:
	CPU(GamePak* cart);
	~CPU();

	Registers reg;

	void Initialize();
	void Reset();

private:
	MemoryManager* _mem;
	GamePak* _cart;
};

