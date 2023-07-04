#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data d(123, "hi");

	std::cout << "Data             : " << d << std::endl;

	uintptr_t serialized = Serializer::serialize(&d);
	std::cout << "Data serialized  : " << serialized << std::endl;
	
	Data* res = Serializer::deserialize(serialized);
	std::cout << "Deserialized obj : " << *res << std::endl;

	std::cout << "Original addr    : " << &d << std::endl;
	std::cout << "Deserial addr    : " << res << std::endl;
	std::string equal = &d == res ? "True" : "False";
	std::cout << "Equality: " << equal << std::endl;

	std::cout << std::endl << "==========================" << std::endl << std::endl;

	Data d2(2147483647, "TOO LONG");

	std::cout << "Data             : " << d2 << std::endl;

	uintptr_t serialized2 = Serializer::proper_serialize(&d2);
	std::cout << "Data serialized  : " << serialized2 << std::endl;
	
	Data* res2 = Serializer::proper_deserialize(serialized2);
	std::cout << "Deserialized obj : " << *res2 << std::endl;

	std::cout << "Original addr    : " << &d2 << std::endl;
	std::cout << "Deserial addr    : " << res2 << std::endl << std::endl;

	delete res2;
	system("leaks serialize");
}
