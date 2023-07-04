#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& other);
		void makeSound() const;
		void setIdea(int num, std::string idea) const;
		std::string getIdea(int num) const;
};

#endif