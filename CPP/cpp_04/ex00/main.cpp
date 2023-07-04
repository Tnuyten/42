#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "creating Animal: " << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl;

	std::cout << "creating Dog: " << std::endl;
	const Animal* dog = new Dog();
	std::cout << std::endl;

	Dog *a = new Dog();
	Animal *b = new Dog(*a);
	b->makeSound();

	std::cout << "creating Cat: " << std::endl;
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << "creating WrongAnimal: " << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "creating WrongCat: " << std::endl;
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << std::endl;

	std::cout << "Get type: " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl << std::endl;

	std::cout << "makeSound: " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Wrong makeSound: " << std::endl;
	wrongcat->makeSound(); //will output the WrongAnimal sound!
	wrongmeta->makeSound(); //ditto
	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;

	delete wrongcat;
	delete wrongmeta;

	return 0;
}