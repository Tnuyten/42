#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap{
	private:
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys();
		std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const FragTrap& ft);

#endif