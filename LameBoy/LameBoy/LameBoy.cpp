// LameBoy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "GamePak.h"
#include "CPU.h"
#include "Translator.h"
#include <iomanip>


int main()
{
    GamePak game("c:\\data\\tetris.gb");

    std::cout << game.Title() << '\n' << Translator::CartType(game.CartType()) << '\n';

    CPU* cp = new CPU(&game);
    BYTE cycles;
    
    while (1 == 1)
    {
        opcode op = cp->PeekNextOpcode();
        std::cout << "0x" << std::setw(2) << std::setfill('0') << std::hex << +(op.code) << " " << op.disassembly << '\n';

        cp->ExecuteNextOpcode(&cycles);

        std::cout << cycles << " cycles used.\n";
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
