#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "HumanB " << this->name << " constructor !" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->name << " destructor !" << std::endl;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}