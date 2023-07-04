#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if(argc != 2)
		std::cout << "Invalid number of arguments" << std::endl;

	Harl h = Harl();
	h.complain(argv[1]);
}