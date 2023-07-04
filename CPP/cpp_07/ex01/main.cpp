#include "iter.hpp"
#include <iostream>

int main() {

	int a[5] = {0, 1, 2, 3, 4};

	iter(a, 5lu, increment);

	for(size_t i = 0; i < 5; i++) {
		std::cout << a[i] << std::endl;
	}

	return 0;
}