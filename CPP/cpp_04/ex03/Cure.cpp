#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Constructed Cure with type " << this->type << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other.type) {
	// std::cout << "Constructed Cure from copy" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this == &other)
		return *this;

	this->type = other.type;

	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure Deconstructed" << std::endl;
}

std::string const & Cure::getType() const {
	return this->type;
}
Cure* Cure::clone() const {
	return new Cure();
}
void Cure::use(ICharacter &target)
{
	AMateria::use(target);
}