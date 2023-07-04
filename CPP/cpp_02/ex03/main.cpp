#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a = Point(0,0);
	Point b = Point(0,5);
	Point c = Point(5,0);

	Point p0 = Point(1.1f, 1.1f);
	Point p1 = Point(0,0);
	Point p2 = Point(5,5);
	Point p3 = Point(1,3);
	Point p4 = Point(3,1);
	Point p5 = Point(1, 1);
	Point p6 = Point(1, -1);
	Point p7 = Point(-1, -1);
	Point p8 = Point(-1,1);
	Point p9 = Point(1234,1234);

	std::cout << "[" << p0.getX().toFloat() << "," << p0.getY().toFloat() << "]: " << bsp(a, b, c, p0) << std::endl;
	std::cout << "[" << p1.getX().toFloat() << "," << p1.getY().toFloat() << "]: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "[" << p2.getX().toFloat() << "," << p2.getY().toFloat() << "]: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "[" << p3.getX().toFloat() << "," << p3.getY().toFloat() << "]: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "[" << p4.getX().toFloat() << "," << p4.getY().toFloat() << "]: " << bsp(a, b, c, p4) << std::endl;
	std::cout << "[" << p5.getX().toFloat() << "," << p5.getY().toFloat() << "]: " << bsp(a, b, c, p5) << std::endl;
	std::cout << "[" << p6.getX().toFloat() << "," << p6.getY().toFloat() << "]: " << bsp(a, b, c, p6) << std::endl;
	std::cout << "[" << p7.getX().toFloat() << "," << p7.getY().toFloat() << "]: " << bsp(a, b, c, p7) << std::endl;
	std::cout << "[" << p8.getX().toFloat() << "," << p8.getY().toFloat() << "]: " << bsp(a, b, c, p8) << std::endl;
	std::cout << "[" << p9.getX().toFloat() << "," << p9.getY().toFloat() << "]: " << bsp(a, b, c, p9) << std::endl;
}