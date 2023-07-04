#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other) {
	for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i].c_str();
	std::cout << "Brain copy constructed" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain deconstructed" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this == &other)
		return *this;

	for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i].c_str();
	return *this;
}

std::string Brain::getIdea(int num) {
	return this->ideas[num];
}

void Brain::setIdea(int num, std::string idea) {
	this->ideas[num] = idea;
}