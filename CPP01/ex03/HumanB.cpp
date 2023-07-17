#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
	std::cout << "HumanB " << this->_name << " constructor !" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->_name << " destructor !" << std::endl;
}

void	HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attact, it got no weapon !" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}