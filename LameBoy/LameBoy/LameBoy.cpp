// LameBoy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GamePak.h"
#include "CPU.h"
#include "Translator.h"
#include <iomanip>

#include "OpcodeNotImplementedException.h"

#define dohax true

int main()
{
    GamePak game("c:\\data\\tetris.gb");

    std::cout << game.Title() << '\n' << Translator::CartType(game.CartType()) << '\n';

    CPU* cp = new CPU(&game);
    BYTE cycles;

    bool skip = true;
    WORD stopskip = 0x2a4;
    WORD MainLoop = 0x02c4;
    
    if (dohax)
    {
        // set 0xff44 to 0x94 so that we can continue loading without PPU emulation
        cp->ld_addr_val(0xff44, 0x94);
    }

    if (skip)
    {
        std::cout << "Skipping to " << std::hex << stopskip << '\n';
    }

    try
    {

        while (1 == 1)
        {
            OPC::opcode op = cp->PeekNextOpcode();
            if (skip && (cp->reg.pc == stopskip || op.code == 0xc9))
            {
                skip = false;
            }

            if (!skip)
            {
                std::cout << "PC: 0x" << std::setw(4) << std::setfill('0') << std::hex << +(cp->reg.pc) << "   0x" << std::setw(2) << std::setfill('0') << std::hex << +(op.code) << " " << op.disassembly << '\n';
            }

            cp->ExecuteNextOpcode(&cycles);

        }
    }
    catch(const OpcodeNotImplException& ex)
    {
        std::cout << ex.what() << "\n0x" << std::setw(2) << std::setfill('0') << std::hex << +(ex.op.code) << " - " << ex.op.disassembly << "  " << +(ex.op.cyles) << "|" << +(ex.op.branchedCycles) 
            << "  FL: " << ex.op.flagInfo <<'\n';

        exit(-1);
    }
    //game.DumpToCout();

  /*  int i;
    i = 0;
    i++;*/

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
