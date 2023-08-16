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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap named constructor !" << std::endl;
	_name = name;
	FragTrap::defineHitPoints(100);
	ScavTrap::defineEnergyPoints(50);
	FragTrap::defineAttackDamage(30);
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
	std::cout << "DiamondTrap " << _name << " is thinking about existence.." << std::endl;
}
