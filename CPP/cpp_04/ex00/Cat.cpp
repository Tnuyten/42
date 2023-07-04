#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructed" << std::endl;
}
Cat::Cat(std::string type) : Animal(type) {
	std::cout << type << " Cat constructed" << std::endl;
}
Cat::~Cat() {
	std::cout << "Cat destructed" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat constructed from copy with type: " << type << std::endl;
}
Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}
void Cat::makeSound() const {
	std::cout << "Miaow" << std::endl;
}