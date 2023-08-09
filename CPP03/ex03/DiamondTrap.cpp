#include "DiamondTrap.hpp"

/* Canonical Form -- START */
DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor !" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor !" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &parent)
{
	std::cout << "DiamondTrap parent constructor !" << std::endl;
	*this = parent;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &parent)
{
	_name = parent._name;
	defineName(parent.getName());
	defineHitPoints(parent.getHitPoints());
	defineEnergyPoints(parent.getEnergyPoints());
	defineAttackDamage(parent.getAttackDamage());
	return (*this);
}
/* Canonical Form -- END */

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap named constructor !" << std::endl;
	defineName(name + "_clap_name");
	_name = name;
	defineHitPoints(FragTrap::getHitPoints());
	defineEnergyPoints(ScavTrap::getEnergyPoints());
	defineAttackDamage(FragTrap::getAttackDamage());
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << _name << " is thinking about existence of it self" << std::endl;
}
