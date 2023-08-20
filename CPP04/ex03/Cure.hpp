#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure& parent);
	Cure& operator=(const Cure& parent);
	~Cure(void);

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};