#include "ClapTrap.hpp"

//Constructors
ClapTrap::ClapTrap() : hp(10), ep(10), ad(0) {
	std::cout << "Default ClapTrap constructor called. I don't have a name!" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0) {
	std::cout << "ClapTrap " << this->name << " constructed" << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " deconstructed" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) {
	this->name = other.name;
	this->hp = other.hp;
	this->ep = other.ep;
	this->ad = other.ad;
}

//Assignment
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other)
		return *this;

	this->name = other.name;
	this->hp = other.hp;
	this->ep = other.ep;
	this->ad = other.ad;

	return *this;
}

// Stream overload
std::ostream& operator<<(std::ostream& os, const ClapTrap& ct) {
	return os << ct.toString();
}

//Public member functions
void ClapTrap::attack(const std::string& target) {
	if(this->hp == 0 || this->ep == 0) {
		std::string reason = this->hp == 0 ? "he's dead" : "he's out of energy";
		std::cout << "ClapTrap " << this->name
				  << " cannot attack " << target
				  << " because " << reason
				  << std::endl;
				  return;
	}

	this->ep -= 1;

	std::cout << "ClapTrap " << this->name
			  << " attacks " << target
			  << ", causing " << this->ad
			  << " points of damage!"
			  << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if(this->hp == 0) {
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	if(this->hp > amount)
		this->hp -= amount;
	else
		this->hp = 0;

	std::cout << "ClapTrap " << this->name
			  << " takes " << amount << " points of damage"
			  << " leaving it at " << this->hp << " hp." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if(this->hp >= 100) {
		std::cout << "ClapTrap " << this->name << " is at full health" << std::endl;
		return;
	}
	if(this->ep == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy left to do repairs" << std::endl;
		return;
	}

	if(amount > (100 - this->hp))
		amount = 100 - this->hp;
	this->hp += amount;
	this->ep -= 1;

	std::cout << "ClapTrap " << this->name
			  << " was repaired for " << amount << "hp." << std::endl;
}
unsigned int ClapTrap::getHP() const {
	return this->hp;
}
unsigned int ClapTrap::getAD() const {
	return this->ad;
}
unsigned int ClapTrap::getEP() const {
	return this->ep;
}
std::string ClapTrap::getName() const {
	return this->name;
}
void ClapTrap::setHP(unsigned int hp) {
	this->hp = hp;
}
void ClapTrap::setAD(unsigned int ad) {
	this->ad = ad;
}
void ClapTrap::setEP(unsigned int ep) {
	this->ep = ep;
}
void ClapTrap::setName(std::string name) {
	this->name = name;
}
std::string ClapTrap::toString() const {
	std::string ss = 	"ClapTrap[\"" +
						this->name + "\"," +
						std::to_string(this->hp) + "," +
						std::to_string(this->ep) + "," +
						std::to_string(this->ad) + "]";
	return ss;
}
