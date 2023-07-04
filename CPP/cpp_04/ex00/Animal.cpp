#include "Animal.hpp"


Animal::Animal() : type("") {
	std::cout << "Animal constructed" << std::endl;
}
Animal::Animal(std::string type) : type(type) {
	std::cout << type << " Animal constructed" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal destructed" << std::endl;
}
Animal::Animal(const Animal& other) {
	this->type = other.type;
	std::cout << "Animal constructed from copy" << std::endl;
}
Animal& Animal::operator=(const Animal& other) {
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Bork" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}