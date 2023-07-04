#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "materia";
	// std::cout << "Default AMateria with type materia constructed" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	// std::cout << "AMateria with type " << type << " constructed" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	this->type = other.type;
	// std::cout << "AMateria constructed from copy" << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMateria deconstructed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
	if (this->type == "materia")
		return;
	if (this->type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}