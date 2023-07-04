#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void operator=(const Zombie& z);
		void announce();
		void setName(std::string name);
};

Zombie *zombieHorde(int n, std::string name);
Zombie *zombieHorde2(int n, std::string name);
Zombie *zombieHorde3(int n, std::string name);

#endif