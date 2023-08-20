#pragma once
#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(const AMateria& parent);
	AMateria& operator=(const AMateria& parent);
	virtual ~AMateria(void) = 0;

	AMateria(std::string const & type);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};