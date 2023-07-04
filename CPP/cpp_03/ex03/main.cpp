#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt = DiamondTrap("Ruby");

	std::cout << dt << std::endl;

	dt.setAD(2);
	dt.setEP(2);

	std::cout << dt << std::endl << std::endl;

	std::cout << "Attack: " << std::endl;
	dt.ScavTrap::attack("Boss");
	std::cout << dt << std::endl;
	dt.ScavTrap::attack("Boss");
	std::cout << dt << std::endl;
	dt.ScavTrap::attack("Boss");
	std::cout << dt << std::endl << std::endl;

	dt.setEP(2);

	std::cout << "TakeDamage: " << std::endl;
	dt.takeDamage(3);
	std::cout << dt << std::endl;
	dt.takeDamage(99);
	std::cout << dt << std::endl;
	dt.takeDamage(1);
	std::cout << dt << std::endl << std::endl;

	std::cout << "BeRepaired: " << std::endl;
	dt.beRepaired(2);
	std::cout << dt << std::endl;
	dt.beRepaired(200);
	std::cout << dt << std::endl;
	dt.beRepaired(3);
	std::cout << dt << std::endl;

	std::cout << "WHOAMI: " << std::endl;
	dt.whoAmI();

	return 0;
}