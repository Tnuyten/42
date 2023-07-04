#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void leaks() {
	system("leaks mats");
}

int main()
{
	atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria* excess[2] = { new Cure(), NULL };
	src->learnMateria(excess[0]); //Is ignored

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	me->use(3, *bob); //is ignored

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	
	excess[1] = src->createMateria("cure");
	me->equip(excess[1]); // Is ignored

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob); // is ignored

	delete bob;
	delete me;
	delete src;
	delete excess[0];
	delete excess[1];

	return 0;
}