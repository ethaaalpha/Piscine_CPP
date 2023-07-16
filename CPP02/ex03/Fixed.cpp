#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int n)
{
	_value = n << this->_bytes;
}

Fixed::Fixed(const float n)
{
	_value = roundf(n * (1 << this->_bytes));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &parent)
{
	*this = parent;
}

int Fixed::toInt() const
{
	return (this->_value >> this->_bytes);
}

float Fixed::toFloat() const
{
	return ((float)this->_value / (float)(1 << this->_bytes));
}

int Fixed::getRawBits() const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed& Fixed::operator=(const Fixed &parent)
{
	_value = parent._value;
	return (*this);
}

bool Fixed::operator>(const Fixed &right) const
{
	return (_value > right._value);
}

bool Fixed::operator<(const Fixed &right) const
{
	return (_value < right._value);
}

bool Fixed::operator>=(const Fixed &right) const
{
	return (_value >= right._value);
}

bool Fixed::operator<=(const Fixed &right) const
{
	return (_value <= right._value);
}

bool Fixed::operator==(const Fixed &right) const
{
	return (_value == right._value);
}

bool Fixed::operator!=(const Fixed &right) const
{
	return (_value != right._value);
}

Fixed Fixed::operator+(const Fixed &right)
{
	return (Fixed(toFloat() + right.toFloat()));
}

Fixed Fixed::operator-(const Fixed &right)
{
	return (Fixed(toFloat() - right.toFloat()));
}

Fixed Fixed::operator*(const Fixed &right)
{
	return (Fixed(toFloat() * right.toFloat()));
}

Fixed Fixed::operator/(const Fixed &right)
{
	return (Fixed(toFloat() / right.toFloat()));
}

// Prefix operator
Fixed& Fixed::operator++(void)
{
	_value++;
	return (*this);
}

// Postfix operator
Fixed Fixed::operator++(int)
{
	Fixed return_value = *this;
	_value++;
	return (return_value);
}

// Prefix operator
Fixed& Fixed::operator--(void)
{
	_value--;
	return (*this);
}

// Postfix operator
Fixed Fixed::operator--(int)
{
	Fixed return_value = *this;
	_value--;
	return (return_value);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream & iostrm, const Fixed &n)
{
	std::cout << (n.toFloat());
	return (iostrm);
}
