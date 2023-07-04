#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon (Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if (weapon == NULL) {
		std::cout << this->name
				  << " attacks with their fists"
				  << std::endl;
		return;
	}
	std::cout << this->name
			  << " attacks with their "
			  << this->weapon->getType()
			  << std::endl;
}