#include "AMateria.hpp"

AMateria::AMateria(void)
{
	// std::cout << "AMateria default constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& parent) 
{
	_type = parent.getType();
	return (*this);
}

AMateria::AMateria(const AMateria& parent)
{
	// std::cout << "AMateria parent constructor" << std::endl;
	*this = parent;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria destructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "AMateria typed constructor" << std::endl; 
}

const std::string& AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Use AMateria on " << target.getName() << std::endl;
 }