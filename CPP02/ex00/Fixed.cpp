#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &parent)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = parent.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &parent)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = parent.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
