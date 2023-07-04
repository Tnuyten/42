#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int num;
		static const int frac = 8;

	public:
		// Constructors
		Fixed();
		Fixed(Fixed const &f);
		~Fixed();
		Fixed(int n);
		Fixed(float n);

		// Assignments
		Fixed& operator=(const Fixed& f);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		// Comparisons
		bool operator<(const Fixed& rhs) const;
		bool operator>(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		// Arithmetics
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		// Stream overloads (See below class)
		// std::ostream& operator<<(std::ostream& os);
		// std::istream& operator>>(std::istream& is);

		// Public member functions
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
std::istream& operator>>(std::istream& is, Fixed& f);

#endif