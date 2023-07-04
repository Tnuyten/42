#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <random>
#include <iostream>

Base* generate(void) {
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_int_distribution<int> dist(0, 2); // Black magic nonsense

	int num = dist(gen);

	switch(num) {
		case 0:
			std::cout << "Generating A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generating B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generating C" << std::endl;
			return new C();
		default:
			std::cout << "Error making derived class" << std::endl;
	}
	return NULL;
}

void identify(Base *p) {
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if(a) {
		std::cout << "Found A. B: " << b << " C: " << c <<std::endl;
		return;
	}
	if(b) {
		std::cout << "Found B. A: " << a << " C: " << c << std::endl;
		return;
	}
	if(c) {
		std::cout << "Found C. A: " << a << " B: " << b << std::endl;
		return;
	}
	std::cout << "None found" << std::endl;
}

void identify(Base &p) {
	// identify(&p); Alternative way to implement this function, but might violate the "Don't use pointers" directive.
	try {
		__attribute__((unused)) A& aobj = dynamic_cast<A&>(p);
		std::cout << "Found A." << std::endl;
	} catch (const std::bad_cast& e) {
	}
	try {
		__attribute__((unused)) B& bobj = dynamic_cast<B&>(p);
		std::cout << "Found B." << std::endl;
	} catch (const std::bad_cast& e) {
	}
	try {
		__attribute__((unused)) C& cobj = dynamic_cast<C&>(p);
		std::cout << "Found C." << std::endl;
	} catch (const std::bad_cast& e) {
	}
}

int main() {
	for(int i = 0; i < 10; i++) {
		Base* base = generate();
		identify(base);
		identify(*base);
		delete base;
	}

	return (0);
}