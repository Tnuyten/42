#include "Fixed.hpp"

Fixed::Fixed() : num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = f.num;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->num >> this->frac;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->num = raw << this->frac;
}