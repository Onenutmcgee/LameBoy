#pragma once
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

class JP_u16_Executor : public OpExecutor
{
public:
	bool execute(CPU* cp);
};

class XOR_a_Executor : public OpExecutor
{
public:
	bool execute(CPU* cp);
};

class LD_hl_u16_Executor : public OpExecutor
{
public:
	bool execute(CPU* cp);
};


