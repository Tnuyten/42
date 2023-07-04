#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("") {
	std::cout << "WrongAnimal constructed" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << type << " WrongAnimal constructed" << std::endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructed" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	this->type = other.type;
	std::cout << "WrongAnimal constructed from copy" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "Bork" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}