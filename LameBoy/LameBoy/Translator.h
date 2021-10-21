#pragma once
#include <string>
#include "TypeDefs.h"

class Translator
{
public:
	static std::string CartType(int val)
	{
		switch (val)
		{
		case CART_TYPE_ROM:
			return "ROM ONLY";
		case CART_TYPE_MBC1:
			return "MBC1";
		case CART_TYPE_MBC1_RAM:
			return "MBC1 + RAM";
		case CART_TYPE_MBC1_RAM_BATT:
			return "MBC1 + RAM + BATTERY";
		case CART_TYPE_MBC2:
			return "MBC2";
		case CART_TYPE_MBC2_BATT:
			return "MBC2 + BATTERY";
		case CART_TYPE_ROM_RAM:
			return "ROM + RAM";
		default:
			return "CART TYPE UNDEFINED";
		}
	}
};

