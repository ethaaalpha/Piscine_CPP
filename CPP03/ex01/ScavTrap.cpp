#include "ScavTrap.hpp"

/* Canonical Form -- START */
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &parent) : ClapTrap(parent)
{
	std::cout << "ScavTrap parent constructor !" << std::endl;
}

ScavTrap ScavTrap::operator=(const ScavTrap &parent)
{
	defineName(parent.getName());
	defineEnergyPoints(parent.getEnergyPoints());
	defineLifePoints(parent.getLifePoints());
	defineAttackDamage(parent.getAttackDamage());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstructor !" << std::endl;
}
/* Canonical Form -- END */

// ScavTrap::ScavTrap(std::string name)
// {
	// define
// }
// 