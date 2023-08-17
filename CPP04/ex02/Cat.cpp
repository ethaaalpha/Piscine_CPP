#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat default constructor !" << std::endl;
	_brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat &parent) : AAnimal(parent)
{
	std::cout << "Cat parent constructor !" << std::endl;
	*this = parent;
}

Cat& Cat::operator=(const Cat &parent)
{
	_brain = new Brain(*(parent._brain));
	type = parent.type;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor !" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow, meow, meow..." << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (_brain);
}