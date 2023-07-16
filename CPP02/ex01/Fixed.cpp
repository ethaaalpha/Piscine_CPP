#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << this->_bytes;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(n * (1 << this->_bytes));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &parent)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = parent;
}

Fixed& Fixed::operator=(const Fixed &parent)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = parent._value;
	return (*this);
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
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

std::ostream& operator<<(std::ostream & iostrm, const Fixed &n)
{
	std::cout << (n.toFloat());
	return (iostrm);
}