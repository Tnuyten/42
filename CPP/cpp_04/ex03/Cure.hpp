#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>
#include "Character.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();
		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter &target);
};

#endif