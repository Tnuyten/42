#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Constructed Ice with type " << type << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other.type) {
	// std::cout << "Constructed Ice from copy" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this == &other)
		return *this;

	this->type = other.type;

	return *this;
}

Ice::~Ice() {
	// std::cout << "Ice Deconstructed" << std::endl;
}

std::string const & Ice::getType() const {
	return this->type;
}
Ice* Ice::clone() const {
	return new Ice();
}
void Ice::use(ICharacter &target)
{
	AMateria::use(target);
}