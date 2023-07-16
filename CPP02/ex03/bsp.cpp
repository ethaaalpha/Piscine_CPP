#include "Point.hpp"

//if positive mean right side, if negative, mean left side
Fixed lineSide(Point lineA, Point lineB, Point point)
{
	Fixed item_a = Fixed(lineA.getX().toFloat() - point.getX().toFloat());
	Fixed item_a2 = Fixed(lineB.getY().toFloat() - point.getY().toFloat());
	Fixed item_b = Fixed(lineA.getY().toFloat() - point.getY().toFloat());
	Fixed item_b2 = Fixed(lineB.getX().toFloat() - point.getX().toFloat());
	return (Fixed(item_a * item_a2 - item_b * item_b2));
}

// true -> 1 | false -> 0
bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	if (a == b || b == c || c == a)
	{
		std::cout << "The coordonnates of the triangle shouldn't be equals (a != b != c)";
		return false;
	}
	if (lineSide(c, a, point) > 0 && lineSide(a, b, point) > 0 && lineSide(b, c, point) > 0)
		return true;
	else if (lineSide(c, a, point) < 0 && lineSide(a, b, point) < 0 && lineSide(b, c, point) < 0)
		return true;
	else
		return false;
}