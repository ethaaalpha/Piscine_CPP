#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	std::cout << "Dog default constructor !" << std::endl;
	_brain = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog &parent) : AAnimal(parent)
{
	std::cout << "Dog parent constructor !" << std::endl;
	*this = parent;
}

Dog& Dog::operator=(const Dog &parent)
{
	_brain = new Brain(*(parent._brain));
	type = parent.type;
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor !" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Wouf, wouf, wouf..." << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (_brain);
}