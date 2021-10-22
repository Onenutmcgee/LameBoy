#pragma once
#include "CPU.h"

class CPU;

class OpExecutor
{
public:
	virtual bool execute(CPU* cp) = 0;
};


class NOP_Executor : public OpExecutor
{
public:
	bool execute(CPU* cp);
};