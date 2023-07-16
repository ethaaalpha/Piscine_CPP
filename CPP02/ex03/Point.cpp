#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
{
}

Point::~Point()
{
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point &parent) : _x(parent.getX()), _y(parent.getY())
{
}

const Fixed& Point::getX(void) const
{
	return (_x);
}

const Fixed& Point::getY(void) const
{
	return (_y);
}

Point& Point::operator=(const Point &parent)
{
	this->~Point();
	new (this) Point(parent.getX().toFloat(), parent.getY().toFloat());
	return (*this);
}

bool Point::operator==(const Point &right) const
{
	if (getX() == right.getX() && getY() == right.getY())
		return (true);
	return (false);
}