#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define UNUSED __attribute__((unused))

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(const Animal& other);
		virtual void makeSound() const = 0;
		std::string getType() const;
		void setType(std::string type);
		virtual void setIdea(UNUSED int num, UNUSED std::string idea) const {};
		virtual std::string getIdea(UNUSED int num) const {std::string empty; return empty;};
};

#endif