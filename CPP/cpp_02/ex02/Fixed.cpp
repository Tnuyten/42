#include "Fixed.hpp"

// Constructors
Fixed::Fixed() : num(0) {}
Fixed::Fixed(Fixed const &f) {
	*this = f;
}
Fixed::~Fixed() {}
Fixed::Fixed(int n) {
	this->setRawBits(n);
}
Fixed::Fixed(float n) {
	num = round(n * (1 << this->frac));
}

// Assignments
Fixed& Fixed::operator=(const Fixed& f) {
	if(this != &f)
		this->num = f.num;
	return *this;
}
Fixed& Fixed::operator++() { //prefix
	this->num++;
	return *this;
}
Fixed Fixed::operator++(int) { //postfix
	Fixed f(*this);
	++(*this);
	return f;
}
Fixed& Fixed::operator--() {
	this->num--;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed f(*this);
	--(*this);
	return f;
}

// Comparisons
bool Fixed::operator<(const Fixed& rhs) const {
	return this->num < rhs.num;
}
bool Fixed::operator>(const Fixed& rhs) const {
	return rhs < *this;
}
bool Fixed::operator<=(const Fixed& rhs) const {
	return !(*this > rhs);
}
bool Fixed::operator>=(const Fixed& rhs) const {
	return !(*this < rhs);
}
bool Fixed::operator==(const Fixed& rhs) const {
	return this->num == rhs.num;
}
bool Fixed::operator!=(const Fixed& rhs) const {
	return !(*this == rhs);
}

// Arithmetics
Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed copy(*this);
	copy.num += rhs.num;
	return copy;
}
Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed copy(*this);
	copy.num -= rhs.num;
	return copy;
}
Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed copy(*this);
	copy.num *= rhs.getRawBits();
	return copy;
}
Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed copy(*this);
	copy.num /= rhs.getRawBits();
	return copy;
}

// Stream overloads
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	return os << f.toFloat();
}
std::istream& operator>>(std::istream& is, Fixed& f) {
	int n;
	is >> n;
	f.setRawBits(n);
	return is;
}

// Public member functions
int Fixed::getRawBits() const {
	return this->num >> this->frac;
}
void Fixed::setRawBits(int const raw) {
	this->num = raw << this->frac;
}
int Fixed::toInt() const {
	return this->getRawBits();
}
float Fixed::toFloat() const {
	float ret = (float)this->num / (float)(1 << this->frac);
	return ret;
}
Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
	if (lhs < rhs)
		return lhs;
	return rhs;
}
const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) { // Might be incorrect?
	if (lhs > rhs)
		return lhs;
	return rhs;
}
Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
	if (lhs > rhs)
		return lhs;
	return rhs;
}
const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) { // Also
	if (lhs > rhs)
		return lhs;
	return rhs;
}