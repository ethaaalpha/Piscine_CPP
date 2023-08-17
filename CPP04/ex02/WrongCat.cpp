#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &parent) : WrongAnimal(parent)
{
	std::cout << "WrongCat parent constructor !" << std::endl;
	*this = parent;
}

WrongCat& WrongCat::operator=(const WrongCat &parent)
{
	type = parent.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor !" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow, meow, meow..." << std::endl;
}