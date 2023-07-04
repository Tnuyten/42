#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructed" << std::endl;
}
WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << type << " WrongCat constructed" << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructed" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat constructed from copy with type: " << type << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}
void WrongCat::makeSound() const {
	std::cout << "Miaow" << std::endl;
}