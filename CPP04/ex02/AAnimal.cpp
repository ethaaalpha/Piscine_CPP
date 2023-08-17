#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	type = "null";
	std::cout << "Animal default constructor !" << std::endl;
}

AAnimal::AAnimal(const AAnimal &parent)
{
	std::cout << "Animal parent constructor !" << std::endl;
	*this = parent;
}

AAnimal& AAnimal::operator=(const AAnimal &parent)
{
	type = parent.type;
	return (*this);
}

std::string AAnimal::getType(void) const
{
	return (type);
}