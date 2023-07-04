#include "FragTrap.hpp"

int main() {
	FragTrap ft = FragTrap("Bassie");

	std::cout << ft << std::endl;

	ft.setAD(2);
	ft.setEP(2);

	std::cout << ft << std::endl << std::endl;

	std::cout << "Attack: " << std::endl;
	ft.attack("Boss");
	std::cout << ft << std::endl;
	ft.attack("Boss");
	std::cout << ft << std::endl;
	ft.attack("Boss");
	std::cout << ft << std::endl << std::endl;

	ft.setEP(2);

	std::cout << "TakeDamage: " << std::endl;
	ft.takeDamage(3);
	std::cout << ft << std::endl;
	ft.takeDamage(99);
	std::cout << ft << std::endl;
	ft.takeDamage(1);
	std::cout << ft << std::endl << std::endl;

	std::cout << "BeRepaired: " << std::endl;
	ft.beRepaired(2);
	std::cout << ft << std::endl;
	ft.beRepaired(200);
	std::cout << ft << std::endl;
	ft.beRepaired(3);
	std::cout << ft << std::endl;

	ft.highFivesGuys();

	return 0;
}