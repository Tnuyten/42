#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
	// std::cout << "Default MateriaSource constructed" << std::endl;
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++) {
		if(this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	// std::cout << "MateriaSource deconstructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for(int i = 0; i < 4; i++) {
		if(other.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = other.inventory[i]->clone();
	}
	// std::cout << "MateriaSource constructed from copy" << std::endl; 
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other)
		return *this;

	for(int i = 0; i < 4; i++)
	{
		if(other.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = other.inventory[i]->clone();
	}
	
	return *this;
}

void MateriaSource::learnMateria(AMateria* mat) {
	for(int i = 0; i < 4; i++) {
		if(this->inventory[i] == NULL)
		{
			this->inventory[i] = mat;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {

	for(int i = 0; i < 4; i++) {
		if(inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return NULL;
}