#ifndef POINT_HPP
# define POINT_HPP

# include "./Fixed.hpp"

class Point {
private:
	const Fixed	_x;
	const Fixed _y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point& other);
	~Point(void);

	Point&	operator=(const Point& ref);

	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif