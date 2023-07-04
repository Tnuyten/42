#include "Character.hpp"

Character::Character() : name("Default") {
	// std::cout << "Default Character constructed" << std::endl;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const name) : name(name) {
	// std::cout << "Character " << name << " constructed" << std::endl;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character() {
	// std::cout << "Character " << this->getName() << " deconstructed" << std::endl;
	for(int i = 0; i < 4; i++) {
		delete this->inventory[i];
	}
}

Character& Character::operator=(const Character& other) {
	if (this == &other)
		return *this;

	for (int i = 0; i < 4; i++) {
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}

	for(int i = 0; i < 4; i++)
	{
		if(other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
	}

	return *this;
}

Character::Character(const Character& other) : name(other.getName()) {
	for(int i = 0; i < 4; i++) {
		if(other.inventory[i] == NULL)
			return;
		this->inventory[i] = other.inventory[i]->clone();
	}
}

std::string const & Character::getName() const {
	return this->name;
}
void Character::equip(AMateria* m) {
	for(int i = 0; i < 4; i++) {
		if(this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return;
		}
	}
}
void Character::unequip(int idx) {
	if(idx >= 4 || idx < 0)
		return;
	this->inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target) {
	if(idx >= 4 || idx < 0)
		return;
	if(this->inventory[idx] == NULL)
		return;
	this->inventory[idx]->use(target);
}
