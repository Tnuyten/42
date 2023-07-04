#include "Harl.hpp"

int main() {
	Harl h = Harl();

	h.complain("debug");
	h.complain("info");
	h.complain("warning");
	h.complain("error");
}