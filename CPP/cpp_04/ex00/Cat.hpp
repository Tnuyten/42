#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		~Cat();

		Cat& operator=(const Cat& other);
		void makeSound() const;
};

#endif