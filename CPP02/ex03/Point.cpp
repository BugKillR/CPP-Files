#include "./Point.hpp"

Point::Point(void) : _x(0), _y(0) { }
Point::Point(const float x, const float y) : _x(x), _y(y) { }
Point::Point(const Point& other) : _x(other._x), _y(other._y) { }
Point::~Point(void) { }

Point&	Point::operator=(const Point& ref) {
	(void)ref;
	return (*this);
}

Fixed	Point::getX(void) const { return _x; }
Fixed	Point::getY(void) const { return _y; }

static Fixed	sign(Point const p1, Point const p2, Point const p3) {
	return (
		(p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())
	);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	d1 = sign(point, a, b);
	Fixed	d2 = sign(point, b, c);
	Fixed	d3 = sign(point, c, a);

	bool	hasNegative	= (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	bool	hasPositive = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return false;
	return !(hasNegative && hasPositive);
}