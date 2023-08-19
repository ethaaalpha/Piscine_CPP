#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure(void);
	Cure(const Cure& parent);
	Cure& operator=(const Cure& parent);
	~Cure(void);
};

Cure::Cure(void) : _type("cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure& parent)
{
	std::cout << "Cure parent constructor" << std::endl;
	*this = parent;
}

Cure& Cure::operator=(const Cure& parent)
{
	
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}
