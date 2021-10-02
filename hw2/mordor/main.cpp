#include <iostream>

#include "Vmordor.h"
#include "verilated.h"

Vmordor *top; // Instantiation of model

int main(int argc, char **argv, char **env)
{
        Verilated::commandArgs(argc, argv);
        Vmordor *top = new Vmordor;
	top->reset_n = 0;
        top->eval();
	top->reset_n = 1; // De-assert reset
        while (!Verilated::gotFinish())
        {
		top->clock = !top->clock; // Toggle clock
        	top->eval();
	}
	top->final();
        delete top;
        exit(0);
}
