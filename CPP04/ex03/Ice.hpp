#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice& parent);
	Ice& operator=(const Ice& parent);
	~Ice(void);

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};