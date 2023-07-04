#include "ScavTrap.hpp"

int main() {
	ScavTrap st = ScavTrap("Sjon");
	std::cout << st << std::endl;

	st.setAD(2);
	st.setEP(2);

	std::cout << st << std::endl << std::endl;

	std::cout << "Attack: " << std::endl;
	st.attack("Boss");
	std::cout << st << std::endl;
	st.attack("Boss");
	std::cout << st << std::endl;
	st.attack("Boss");
	std::cout << st << std::endl << std::endl;

	st.setEP(2);

	std::cout << "TakeDamage: " << std::endl;
	st.takeDamage(3);
	std::cout << st << std::endl;
	st.takeDamage(99);
	std::cout << st << std::endl;
	st.takeDamage(1);
	std::cout << st << std::endl << std::endl;

	std::cout << "BeRepaired: " << std::endl;
	st.beRepaired(2);
	std::cout << st << std::endl;
	st.beRepaired(200);
	std::cout << st << std::endl;
	st.beRepaired(3);
	std::cout << st << std::endl;

	st.guardGate();

	return 0;
}
