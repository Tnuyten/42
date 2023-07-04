#include "Dog.hpp"


Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructed" << std::endl;
}
Dog::Dog(std::string type) : Animal(type) {
	std::cout << type << " Dog constructed" << std::endl;
}
Dog::~Dog() {
	std::cout << "Dog destructed" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog constructed from copy with type: " << type << std::endl;
}
Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;

	this->type = other.type;
	return *this;
}
void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}