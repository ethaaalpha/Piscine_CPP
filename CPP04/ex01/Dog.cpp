#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor !" << std::endl;
}

Dog::Dog(const Dog &parent)
{
	*this = parent;
}

Dog& Dog::operator=(const Dog &parent)
{
	type = parent.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor !" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Wouf, wouf, wouf..." << std::endl;
}
