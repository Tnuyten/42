#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		// Constructors
		Point();
		~Point();
		Point(const Point&);
		Point(const float x, const float y);

		// Assignments
		Point& operator=(const Point& f);

		// Public member functions
		Fixed getX();
		Fixed getY();

		// Static public member functions
		static float cross_product(Point a1, Point a2, Point b1, Point b2);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif