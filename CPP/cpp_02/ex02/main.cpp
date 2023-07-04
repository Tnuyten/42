#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed c( 5.05f );
	Fixed d( 2 );
	Fixed const b(c * d);

	std::cout << a << std::endl << std::endl;

	std::cout << ++a << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << a++ << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << c << " -- " << d << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;
	return 0;
}