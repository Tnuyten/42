#include "Point.hpp"

// Constructors
Point::Point() : x(0), y(0) {}
Point::~Point() {}
Point::Point(const Point& p) : x(p.x), y(p.y) {}
Point::Point(const float x, const float y) : x(x), y(y) {}

// Assignments
// not possible to do properly with const members.
Point& Point::operator=(const Point&) {
	return *this;
}

Fixed Point::getX() {
	return this->x;
}

Fixed Point::getY() {
	return this->y;
}

float Point::cross_product(Point a1, Point a2, Point b1, Point b2) {
	float a1x, a1y, a2x, a2y;
	float b1x, b1y, b2x, b2y;

	a1x = a1.x.toFloat();
	a1y = a1.y.toFloat();
	a2x = a2.x.toFloat();
	a2y = a2.y.toFloat();

	b1x = b1.x.toFloat();
	b1y = b1.y.toFloat();
	b2x = b2.x.toFloat();
	b2y = b2.y.toFloat();

	float vax = a2x - a1x;
	float vay = a2y - a1y;

	float vbx = b2x - b1x;
	float vby = b2y - b1y;

	return (vax*vby - vay*vbx);
}