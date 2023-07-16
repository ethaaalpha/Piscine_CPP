#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP
#include <iostream>

class Fixed
{
private:
	int				 _value;
	static const int _bytes = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &parent);
	~Fixed();
	Fixed& operator=(const Fixed &parent);

	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream & iostrm, const Fixed &n);
#endif
