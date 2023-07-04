#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& other);
		void attack(const std::string& target);
		void whoAmI();
		std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const DiamondTrap& ft);

#endif