#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "Default Cat constructed" << std::endl;
}
Cat::Cat(std::string type) : Animal(type) {
	this->brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	delete this->brain;
	this->brain = new Brain(*other.brain);
	std::cout << "Cat constructed from copy" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;

	this->type = other.type;
	this->brain = new Brain(*other.brain);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miaow" << std::endl;
}

void Cat::setIdea(int num, std::string idea) const {
	this->brain->setIdea(num, idea);
}

std::string Cat::getIdea(int num) const {
	return this->brain->getIdea(num);
}
