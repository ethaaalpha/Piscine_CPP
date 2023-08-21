#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& parent)
{
	std::cout << "MateriaSource parent constructor" << std::endl;
	(*this) = parent;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& parent)
{
	for (int i = 0; i < 4; i++)
		_memory[i] = parent._memory[i];
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
}

void MateriaSource::learnMateria(AMateria* source)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] == NULL)
		{
			std::cout << "You learnt a new Materia : " << source->getType() << " (" << i << ")" << std::endl;
			_memory[i] = source;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != NULL && _memory[i]->getType() == type)
			return (_memory[i]->clone());
	}
	std::cout << "You don't already know Materia : " << type << std::endl; 
	return (NULL);
}