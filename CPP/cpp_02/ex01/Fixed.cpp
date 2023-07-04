#include "Fixed.hpp"

Fixed::Fixed() : num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int n) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n);
}

int Fixed::toInt() const {
	return this->getRawBits();
}

// https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
Fixed::Fixed(float n) {
	std::cout << "Float constructor called" << std::endl;
	this->num = roundf(n * (1 << this->frac));
}

float Fixed::toFloat() const {
	float ret = (float)this->num / (float)(1 << this->frac);
	return ret;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = f.num;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	return os << f.toFloat();
}

int Fixed::getRawBits() const {
	return this->num >> this->frac;
}

void Fixed::setRawBits(int const raw) {
	this->num = raw << this->frac;
}