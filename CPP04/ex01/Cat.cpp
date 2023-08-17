#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor !" << std::endl;
}

Cat::Cat(const Cat &parent)
{
	*this = parent;
}

Cat& Cat::operator=(const Cat &parent)
{
	type = parent.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor !" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow, meow, meow..." << std::endl;
}