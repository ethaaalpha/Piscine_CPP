#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Weapon constructor !" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor !" << std::endl;
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

std::string	Weapon::getType() const
{
	return (this->type);
}