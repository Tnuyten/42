#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float ap_ab = Point::cross_product(a, point, a, b);
	float bp_bc = Point::cross_product(b, point, b, c);
	float cp_ca = Point::cross_product(c, point, c, a);

	if(ap_ab > 0 && bp_bc > 0 && cp_ca > 0) {
		return 1;
	}
	if(ap_ab < 0 && bp_bc < 0 && cp_ca < 0) {
		return 1;
	}

	return 0;
}