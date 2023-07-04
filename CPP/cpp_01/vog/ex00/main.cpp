#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	Zombie* bill = new Zombie("Bill Clinton");
	bill->announce();

	Zombie* dude = newZombie("Dude");
	dude->announce();

	randomChump("Hillary");

	delete dude;
	delete bill;
	return 0;
}