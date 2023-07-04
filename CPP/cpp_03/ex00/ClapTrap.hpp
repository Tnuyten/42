#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string name;
		unsigned int hp;
		unsigned int ep;
		unsigned int ad;
	public:
		//Constructors
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& ct);

		//Assignment
		ClapTrap& operator=(const ClapTrap& ct);

		//Public member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getHP() const;
		unsigned int getAD() const;
		unsigned int getEP() const;
		std::string getName() const;
		void setHP(unsigned int hp);
		void setAD(unsigned int ad);
		void setEP(unsigned int ep);
		void setName(std::string name);
		std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& ct);

#endif