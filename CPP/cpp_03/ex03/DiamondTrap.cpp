#include "DiamondTrap.hpp"

//Constructors
DiamondTrap::DiamondTrap() {
	std::cout << "Default DiamondTrap constructed. Name is: empty." << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	this->name = name;
	this->hp = this->FragTrap::hp; // 100
	this->ep = this->ScavTrap::ep; // 50
	this->ad = this->FragTrap::ad; // 30

	std::cout << "DiamondTrap " << this->name << " constructed" << std::endl;
	std::cout << "With hp: " << this->hp << " and ep: " << this->ep << " and ad: " << this->ad << std::endl;
	std::cout << "CT: " << this->ClapTrap::name << " FT: " << this->FragTrap::name << " ST: " << this->ScavTrap::name << std::endl;
}
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " deconstructed" << std::endl;
};
void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

// Assignment
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this == &other)
		return *this;

	this->name = other.name;
	this->setName(other.getName());
	this->setHP(other.getHP());
	this->setEP(other.getEP());
	this->setAD(other.getAD());

	return *this;
}

//Public member functions
void DiamondTrap::whoAmI() {
	std::cout << this->name << std::endl;
	std::cout << ClapTrap::name << std::endl;
}
std::string DiamondTrap::toString() const {
	std::string ss =	"DiamondTrap[\"" +
						this->name + "\"," +
						std::to_string(this->hp) + "," +
						std::to_string(this->ep) + "," +
						std::to_string(this->ad) + "]";
	return ss;
}

// Outside class function(s).
std::ostream& operator<<(std::ostream& os, const DiamondTrap& dt) {
	return os << dt.toString();
}