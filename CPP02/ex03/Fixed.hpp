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

	bool operator>(const Fixed &parent) const;
	bool operator<(const Fixed &parent) const;
	bool operator>=(const Fixed &parent) const;
	bool operator<=(const Fixed &parent) const;
	bool operator==(const Fixed &parent) const;
	bool operator!=(const Fixed &parent) const;
	Fixed& operator=(const Fixed &parent);
	Fixed operator+(const Fixed &right);
	Fixed operator-(const Fixed &right);
	Fixed operator*(const Fixed &right);
	Fixed operator/(const Fixed &right);
	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

	static Fixed& min(Fixed &a, Fixed &b);
	static Fixed min(const Fixed &a, const Fixed &b);

	static Fixed& max(Fixed &a, Fixed &b);
	static Fixed max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream & iostrm, const Fixed &n);
#endif
