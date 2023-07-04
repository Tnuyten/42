#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private: 
		std::string const name;
		AMateria* inventory[4];
	public:
		Character();
		Character(std::string const name);
		~Character();
		Character& operator=(const Character& other);
		Character(const Character& other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		// AMateria* getMateria(int idx) const;
};

#endif