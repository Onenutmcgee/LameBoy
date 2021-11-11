#pragma once
#include "MemoryManager.h"

class Timer
{
public:
	Timer(MemoryManager* mem);

	void Update(int cycles);

private:
	MemoryManager* _mem;
};

