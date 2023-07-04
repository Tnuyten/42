#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer {
	private:
		//OCCF
		Serializer();
		Serializer(const Serializer& other);
		~Serializer();
		Serializer& operator=(const Serializer& other);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t val);

		static uintptr_t	proper_serialize(Data *obj);
		static Data*		proper_deserialize(uintptr_t val);
};

#endif
