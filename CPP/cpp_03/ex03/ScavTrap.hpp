#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap{
	protected:
		int mode;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		void guardGate();
		void stopGuard();
		void attack(const std::string& target);
		std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const ScavTrap& st);

#endif