#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *a = new Animal(); // Will not compile, as intended.

	return 0;
}