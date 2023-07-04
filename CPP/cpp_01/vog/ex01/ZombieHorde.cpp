#include "Zombie.hpp"

// Correct.
Zombie* zombieHorde(int n, std::string name) {
	if (n < 0)
		throw std::domain_error("Can't allocate negative zombies.");
	Zombie* horde = new Zombie[n]();
	for(int i = 0; i < n; i++) {
		horde[i].setName(name);
	}
	return horde;
}

// (Almost?) correct, but instantiates two Zombies for each n.
Zombie* zombieHorde2(int n, std::string name) {
	if (n < 0)
		throw std::domain_error("Can't allocate negative zombies.");
	Zombie* horde = new Zombie[n]();
	for(int i = 0; i < n; i++) {
		horde[i] = Zombie(name);
	}
	return horde;
}

// Again correct, but WTF. Allocates heap space for n zombies without instantiating them immediately.
// Then places new zombies in that space with the name constructor.
#include <memory> // In cpp stdlib
Zombie* zombieHorde3(int n, std::string name) {
	if (n < 0)
		throw std::domain_error("Can't allocate negative zombies.");
	Zombie* horde = (Zombie*)new char[n * sizeof(Zombie)];
	for(int i = 0; i < n; i++) {
		new(&horde[i]) Zombie(name);
	}
	return horde;
}