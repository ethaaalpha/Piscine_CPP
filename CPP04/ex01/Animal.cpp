#include "Animal.hpp"

Animal::Animal(void)
{
	type = "null";
	std::cout << "Animal default constructor !" << std::endl;
}

Animal::Animal(const Animal &parent)
{
	std::cout << "Animal parent constructor !" << std::endl;
	*this = parent;
}

Animal& Animal::operator=(const Animal &parent)
{
	type = parent.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor !" << std::endl;
}

std::string Animal::getType(void) const
{
	return (type);
}

void Animal::makeSound(void) const
{
	std::cout << "* insert animal type sound *" << std::endl;
}