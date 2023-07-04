#include "ClapTrap.hpp"

int main() {
	ClapTrap ct = ClapTrap("Henk");
	std::cout << ct << std::endl;

	ct.setAD(2);
	ct.setEP(2);

	std::cout << ct << std::endl << std::endl;

	std::cout << "Attack: " << std::endl;
	ct.attack("Boss");
	std::cout << ct << std::endl;
	ct.attack("Boss");
	std::cout << ct << std::endl;
	ct.attack("Boss");
	std::cout << ct << std::endl << std::endl;

	ct.setEP(2);

	std::cout << "TakeDamage: " << std::endl;
	ct.takeDamage(3);
	std::cout << ct << std::endl;
	ct.takeDamage(99);
	std::cout << ct << std::endl;
	ct.takeDamage(1);
	std::cout << ct << std::endl << std::endl;

	std::cout << "BeRepaired: " << std::endl;
	ct.beRepaired(2);
	std::cout << ct << std::endl;
	ct.beRepaired(200);
	std::cout << ct << std::endl;
	ct.beRepaired(3);
	std::cout << ct << std::endl;

	return 0;
}