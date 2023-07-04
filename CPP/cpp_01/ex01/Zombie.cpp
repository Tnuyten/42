#include "Zombie.hpp"
Zombie::Zombie() {
	std::cout << "New Zombie constructed." << std::endl;
}
Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << this->name << " constructed." << std::endl;
}
Zombie::~Zombie() {
	std::cout << this->name << " destructed." << std::endl;
}
void Zombie::operator=(const Zombie& z) {
	this->name = z.name;
}
void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name) {
	this->name = name;
}