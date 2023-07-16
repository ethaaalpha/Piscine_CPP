#include <iostream>
#include "Point.hpp"

int main( void ) {
	
	Point cible = Point(2, 1);
	Point a = Point(0, 3);
	Point b = Point(0, 0);
	Point c = Point(4, 2);
	c = b;
	std::cout << "a : " << a.getX() << " " << a.getY() << std::endl;
	std::cout << "b : " << b.getX() << " " << b.getY() << std::endl;
	std::cout << "c : " << c.getX() << " " << c.getY() << std::endl;
	std::cout << bsp(a, b, c, cible) << "<- résultat" << std::endl;
	return (0);
}