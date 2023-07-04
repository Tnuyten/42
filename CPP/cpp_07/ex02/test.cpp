#include "Array.hpp"
#include <iostream>

int main() {
	Array<int> intArr = Array<int>(5);

	for (size_t i = 0; i < intArr.size(); i++) {
		intArr[i] = i;
		std::cout << i << ": " << intArr[i] << std::endl;
	}
	std::cout << "===================" << std::endl;

	Array<std::string> strArr = Array<std::string>(3);

	for (size_t i = 0; i < strArr.size(); i++) {
		strArr[i] = "This is item " + std::to_string(i) + ".";
	}

	for (size_t i = 0; i < strArr.size(); i++) {
		std::cout << strArr[i] << std::endl;
	}
	std::cout << "===================" << std::endl;

	// Array<std::string> cpy = strArr;
	Array<std::string> cpy = Array<std::string>(strArr);

	for(size_t i = 0; i < strArr.size(); i++) {
		std::cout << strArr[i] << std::endl;
		std::cout << cpy[i] << std::endl << std::endl;
	}
	std::cout << "===================" << std::endl;

	for(size_t i = 0; i < cpy.size(); i++) {
		cpy[i] = "Other string " + std::to_string(i) + "...";
	}

	for(size_t i = 0; i < strArr.size(); i++) {
		std::cout << strArr[i] << std::endl;
		std::cout << cpy[i] << std::endl << std::endl;
	}
}