#include "Serializer.hpp"

//OCCF
// Serializer::Serializer() {}
// Serializer::Serializer(const Serializer &other) {}
// Serializer::~Serializer() {}
// Serializer &Serializer::operator=(const Serializer &other) {return *this;}

uintptr_t Serializer::serialize(Data *obj) {
	return reinterpret_cast<uintptr_t>(obj);
}

Data* Serializer::deserialize(uintptr_t obj) {
	return reinterpret_cast<Data *>(obj);
}

uintptr_t convertCharArrayToNumber(unsigned char* array) {
	uintptr_t number = 0;
	for (size_t i = 0; i < sizeof(uintptr_t); ++i) {
		number <<= sizeof(uintptr_t);
		number |= static_cast<unsigned char>(array[i]);
	}
	return number;
}

unsigned char*	convertNumberToCharArray(uintptr_t num) {
	unsigned char *res = new unsigned char[sizeof(unsigned char) * sizeof(uintptr_t)];

	for (size_t i = sizeof(uintptr_t) - 1; i >= 0 && i < sizeof(uintptr_t); i--) {
		res[i] = static_cast<unsigned char>(num & 0xFF);
		num >>= sizeof(uintptr_t);
	}
	return res;
}

uintptr_t Serializer::proper_serialize(Data *obj) {
	size_t maxsize = sizeof(uintptr_t);
	unsigned char buf[sizeof(uintptr_t)]; //No VLA, can't DRY.

	int di = obj->getDataInt();
	std::string ds = obj->getDataString();

	unsigned char* cpy = new unsigned char[ds.length() + 1];
	memcpy(cpy, ds.c_str(), maxsize - sizeof(int));

	memcpy(buf, &di, sizeof(int));
	memcpy(buf + sizeof(int), cpy, maxsize - sizeof(int));

	free(cpy);
	return (convertCharArrayToNumber(buf));
}

Data *Serializer::proper_deserialize(uintptr_t val)
{
	Data *obj = new Data();

	unsigned char *buf = convertNumberToCharArray(val);

	int dataInt;
	memcpy(&dataInt, buf, sizeof(int));

	size_t maxsize = sizeof(uintptr_t);
	obj->setDataInt(dataInt);
	obj->setDataString(std::string((char *)buf + sizeof(int), maxsize - sizeof(int)));

	delete buf;
	return obj;
}
