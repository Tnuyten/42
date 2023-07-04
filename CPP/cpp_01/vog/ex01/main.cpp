#include "Zombie.hpp"

void test();

int main() {
	test();

	system("leaks zombie");
	return 0;
}

void test() {
	int num_z = 5;

	{
		std::cout << "Z1:" << std::endl;
		Zombie* horde = zombieHorde(num_z, "Zombo");
		for(int i = 0; i < num_z; i++) {
			horde[i].announce();
		}

		delete [] horde;
	}

	{
		std::cout << "Z2:" << std::endl;
		Zombie* horde = zombieHorde2(num_z, "Zombo");
		for(int i = 0; i < num_z; i++) {
			horde[i].announce();
		}

		delete [] horde;
	}

	{
		std::cout << "Z3:" << std::endl;
		Zombie* horde = zombieHorde3(num_z, "Zombo");
		for(int i = 0; i < num_z; i++) {
			horde[i].announce();
		}

		for(int i = 0; i < num_z; i++) {
			horde[i].~Zombie();
		}
		delete [] (char*) horde;
	}
}