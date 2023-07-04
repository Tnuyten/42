#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() {
	std::cout << "Default FragTrap constructed. Also nameless" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
	std::cout << "FragTrap " << this->getName() << " constructed" << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->getName() << " deconstructed" << std::endl;
}

//Public member functions
void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->getName() << " wants a high five." << std::endl;
}
void FragTrap::attack(const std::string& target) {
	if(this->getHP() == 0 || this->getEP() == 0) {
		std::string reason = this->getHP() == 0 ? "he's dead" : "he's out of energy";
		std::cout << "FragTrap " << this->getName()
				  << " cannot attack " << target
				  << " because " << reason
				  << std::endl;
				  return;
	}
	this->setEP(this->getEP() - 1);

	std::cout << "FragTrap " << this->getName()
			  << " attacks " << target
			  << ", causing " << this->getAD()
			  << " points of damage!"
			  << std::endl;
}
std::string FragTrap::toString() const {
	std::string ss =	"FragTrap[\"" +
						this->getName() + "\"," +
						std::to_string(this->getHP()) + "," +
						std::to_string(this->getEP()) + "," +
						std::to_string(this->getAD()) + "]";
	return ss;
}

// Outside class function(s).
std::ostream& operator<<(std::ostream& os, const FragTrap& ft) {
	return os << ft.toString();
}