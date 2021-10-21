#include "CPU.h"

CPU::CPU(GamePak* cart)
{
	this->_cart = cart;
	this->_mem = new MemoryManager(cart);
	Initialize();
}

CPU::~CPU()
{
	delete _mem;
}

void CPU::Initialize()
{
	reg.af = 0x01B0;
	reg.bc = 0x0013;
	reg.de = 0x00D8;
	reg.hl = 0x014D;
	reg.pc = 0x0100;
	reg.sp = 0xFFFE;
}

void CPU::Reset()
{
	_mem->Initialize();
	Initialize();
}