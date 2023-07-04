#include <iostream>

int main() {
	std::string brain = "HI THIS IS BRAIN";

	std::string* brain_ptr = &brain;
	std::string& brain_ref = brain;

	std::cout << &brain << std::endl;
	std::cout << brain_ptr << std::endl;
	std::cout << &brain_ref << std::endl;

	std::cout << brain << std::endl;
	std::cout << *brain_ptr << std::endl;
	std::cout << brain_ref << std::endl;
}