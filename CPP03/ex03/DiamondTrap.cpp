#include "DiamondTrap.hpp"

/* Canonical Form -- START */
DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor !" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor !" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &parent)
{
	std::cout << "DiamondTrap parent constructor !" << std::endl;
	*this = parent;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &parent)
{
	_name = parent._name;
	defineName(parent.getName());
	defineHitPoints(parent.getHitPoints());
	defineEnergyPoints(parent.getEnergyPoints());
	defineAttackDamage(parent.getAttackDamage());
	return (*this);
}
/* Canonical Form -- END */
#include <stdio.h>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap named constructor !" << std::endl;
	_name = name;
	printf("energy scav %d | frag %d\n", ScavTrap::getEnergyPoints(), FragTrap::getEnergyPoints());
	defineHitPoints(FragTrap::getHitPoints());
	defineEnergyPoints(ScavTrap::getEnergyPoints());
	defineAttackDamage(FragTrap::getAttackDamage());
}

std::string DiamondTrap::getDiamondName(void)
{
	return (_name);
} 

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << _name << " is thinking about existence of it self" << std::endl;
}
