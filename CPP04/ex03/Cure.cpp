#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure& parent) : AMateria(parent.getType())
{
	// std::cout << "Cure parent constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& parent)
{
	_type = parent.getType();
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure destructor" << std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
