#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _memory[4];
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& parent);
	MateriaSource&  operator=(const MateriaSource& parent);
	~MateriaSource(void);

	void learnMateria(AMateria* source);
	AMateria* createMateria(std::string const & type);
};

