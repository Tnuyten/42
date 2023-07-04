#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void run() {
	system("leaks zoo");
}

int main()
{
	// atexit(run);

	Animal *zoo[10];

	std::cout << "Creating animals: " << std::endl;
	for(int i = 0; i < 10; i++) {
		if(i % 2 == 0) {
			zoo[i] = new Cat();
			zoo[i]->setIdea(0,"Catfood is good.");
			std::cout << std::endl;
		}
		else {
			zoo[i] = new Dog();
			zoo[i]->setIdea(0,"Dogfood is good.");
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Getting ideas: " << std::endl;
	for(int i = 0; i < 10; i++) {
		std::cout << zoo[i]->getIdea(0) << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Creating copies: " << std::endl;
	// Heep deep copy
	Animal *copy = new Animal(*zoo[0]);
	copy->setIdea(0, "Dogs are bad mmkay.");
	delete copy;
	{ // Stack deep copy
		Animal copy2 = Animal(*zoo[1]);
		copy2.setIdea(0, "Cats are bad mmkay.");
	} // Copy2 is deleted at end of scope.

	std::cout << std::endl;
	std::cout << ((Dog*)zoo[0])->getIdea(0) << std::endl; //Original objects are untouched.
	std::cout << ((Dog*)zoo[1])->getIdea(0) << std::endl; //Original objects are untouched.

	std::cout << std::endl << std::endl;
	std::cout << "Deleting animals: " << std::endl;
	for(int i = 0; i < 10; i++) {
		delete zoo[i];
		std::cout << std::endl;
	}

	return 0;
}