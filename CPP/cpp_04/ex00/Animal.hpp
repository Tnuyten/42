#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();


		Animal& operator=(const Animal& other);
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
};

#endif