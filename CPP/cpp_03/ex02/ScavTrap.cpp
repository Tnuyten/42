#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap constructed. Still Unnamed." << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
	std::cout << "ScavTrap " << this->getName() << " constructed" << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->getName() << " deconstructed" << std::endl;
}

//Public member functions
void ScavTrap::guardGate() {
	this->mode = 1;
	std::cout << "ScavTrap " << this->getName() << " now guards some gate." << std::endl;
}
void ScavTrap::stopGuard() {
	this->mode = 0;
	std::cout << "ScavTrap " << this->getName() << " stopped guarding some gate." << std::endl;
}
void ScavTrap::attack(const std::string& target) {
	if(this->getHP() == 0 || this->getEP() == 0) {
		std::string reason = this->getHP() == 0 ? "he's dead" : "he's out of energy";
		std::cout << "ScavTrap " << this->getName()
				  << " cannot attack " << target
				  << " because " << reason
				  << std::endl;
				  return;
	}
	this->setEP(this->getEP() - 1);

	std::cout << "ScavTrap " << this->getName()
			  << " attacks " << target
			  << ", causing " << this->getAD()
			  << " points of damage!"
			  << std::endl;
}
std::string ScavTrap::toString() const {
	std::string ss =	"ScavTrap[\"" +
						this->getName() + "\"," +
						std::to_string(this->getHP()) + "," +
						std::to_string(this->getEP()) + "," +
						std::to_string(this->getAD()) + "]";
	return ss;
}

// Outside class function(s).
std::ostream& operator<<(std::ostream& os, const ScavTrap& st) {
	return os << st.toString();
}