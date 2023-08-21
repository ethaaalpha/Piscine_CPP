#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice& parent) : AMateria(parent.getType())
{
	std::cout << "Ice parent constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& parent)
{
	_type = parent.getType();
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}