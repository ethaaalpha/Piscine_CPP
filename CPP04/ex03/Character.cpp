#include "Character.hpp"

Character::Character()
{
	// std::cout << "Character default constructor" << std::endl;
	_name = "default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& parent)
{
	// std::cout << "Character parent constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = parent;
}

Character& Character::operator=(const Character& parent)
{
	_name = parent.getName();
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete (_inventory[i]);
		if (parent._inventory[i] == NULL)	
			_inventory[i] = NULL;
		else
			_inventory[i] = parent._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	// std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete (_inventory[i]);
		}
	}
}

Character::Character(std::string name)
{
	std::cout << "Character named constructor" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

const std::string& Character::getName() const
{
	return (_name);
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	std::cout << "Character " << _name << " unequip " << _inventory[idx]->getType() << " from inventory (" << idx << ")" << std::endl;
	_inventory[idx] = NULL;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			std::cout << "Character " << _name << " equip " << m->getType() << " from inventory (" << i << ")" << std::endl;
			_inventory[i] = m;
			return ;
		}
	}
}