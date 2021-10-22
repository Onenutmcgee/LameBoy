#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "opcode.h"

using namespace std;

class OpcodeNotImplException : public exception
{
public:
	OpcodeNotImplException(OPC::opcode opc)
	{
		this->op = opc;
	}

	OPC::opcode op;

	virtual const char* what() const throw()
	{
		return "Opcode has not been implemented.";
	}
};