#pragma once

typedef unsigned char BYTE;
typedef char SIGNED_BYTE;
typedef unsigned short WORD;
typedef signed short SIGNED_WORD;

#define CART_MODE_CGB  0x80
#define CART_MODE_GB   0x00

// There are other types, but 
#define CART_TYPE_ROM 				0
#define CART_TYPE_MBC1 				1
#define CART_TYPE_MBC1_RAM	        2
#define CART_TYPE_MBC1_RAM_BATT		3
#define CART_TYPE_MBC2				5
#define CART_TYPE_MBC2_BATT			6
#define CART_TYPE_ROM_RAM			9

