#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon constructor !" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor !" << std::endl;
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}

const std::string& Weapon::getType() const
{
	return (this->_type);
}