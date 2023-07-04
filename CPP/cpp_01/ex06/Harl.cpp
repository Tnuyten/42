#include "Harl.hpp"

int switchitup(std::string level) {
	std::string strs[4] = {"debug", "info", "warning", "error"};

	for(int i = 0; i < 4; i++) {
		if (level.compare(strs[i]) == 0)
			return i;
	}
	return -1;
}

void Harl::debug() {
	std::cout << "some debug message here" << std::endl;
}
void Harl::info() {
	std::cout << "some info message here" << std::endl;
}
void Harl::warning() {
	std::cout << "some warning message here" << std::endl;
}
void Harl::error() {
	std::cout << "some error message here" << std::endl;
}
void Harl::complain(std::string level) {
	fps fps = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string strs[4] = {"debug", "info", "warning", "error"};

	switch (switchitup(level)) {
		case 0:
			(this->*fps[0])();
		case 1:
			(this->*fps[1])();
		case 2:
			(this->*fps[2])();
		case 3:
			(this->*fps[3])();
			break;
		default:
			std::cout << "Not a valid complaint level.";
	}
}