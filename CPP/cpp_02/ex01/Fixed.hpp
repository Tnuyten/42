#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int num;
		static const int frac = 8;

	public:
		Fixed();
		Fixed(Fixed const &f);
		~Fixed();
		Fixed(int n);
		Fixed(float n);

		Fixed& operator=(const Fixed& f);

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif