#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>

// OCCF
template <typename T>
Array<T>::Array() {
	this->data = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->data;
}

template <typename T>
Array<T>::Array(const Array& other) {
	if (this != &other) {
		this->data = new T[other.size()];
		for (size_t i = 0; i < other.size(); i++) {
			this->data[i] = other.data[i];
		}
		this->_size = other.size();
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] this->data;
		this->data = new T[other.size()];
		for (size_t i = 0; i < other.size(); i++) {
			this->data[i] = other.data[i];
		}
		this->_size = other.size();
	}
	return *this;
}

// Other constructors
template <typename T>
Array<T>::Array(unsigned int n) {
	this->data = new T[n];
	this->_size = n;
}

// Other operator overloads
template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw Array::OutOfBoundsException();
	return this->data[index];
}

// Public functions
template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

// Exception classes
template <typename T>
const char * Array<T>::OutOfBoundsException::what() const _NOEXCEPT {
	return "Array index is out of bounds";
}

#endif