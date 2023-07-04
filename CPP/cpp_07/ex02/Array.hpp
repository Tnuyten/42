#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
	private:
		T* data;
		unsigned int _size;
		int asdf;
	public:
		// OCCF:
		Array();
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);

		// Other constructors:
		Array(unsigned int n);

		// Other operator overloads:
		T& operator[](unsigned int index);

		// Public functions
		unsigned int size() const;

		// Exception classes
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const _NOEXCEPT;
		};
};

#include "Array.tpp"

#endif
