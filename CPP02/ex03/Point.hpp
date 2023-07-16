#ifndef POINT_CLASS_HPP
#define POINT_CLASS_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &parent);
	~Point();
	Point& operator=(const Point &parent);
	bool   operator==(const Point &right) const;

	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);
#endif