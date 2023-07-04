#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	std::cout << "Default Dog constructed" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	this->brain = new Brain();
	std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	delete this->brain;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog constructed from copy with type: " << type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;

	this->brain = new Brain(*other.brain);
	this->type = other.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

void Dog::setIdea(int num, std::string idea) const {
	this->brain->setIdea(num, idea);
}
std::string Dog::getIdea(int num) const {
	return this->brain->getIdea(num);
}