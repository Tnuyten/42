#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	private:
		Brain* brain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		~Cat();

		Cat& operator=(const Cat& other);
		void makeSound() const;
		void setIdea(int num, std::string idea) const;
		std::string getIdea(int num) const;
};

#endif