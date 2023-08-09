#include "ScavTrap.hpp"

/* Canonical Form -- START */
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &parent) : ClapTrap(parent)
{
	std::cout << "ScavTrap parent constructor !" << std::endl;
	*this = parent;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &parent)
{
	defineName(parent.getName());
	defineEnergyPoints(parent.getEnergyPoints());
	defineHitPoints(parent.getHitPoints());
	defineAttackDamage(parent.getAttackDamage());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstructor !" << std::endl;
}
/* Canonical Form -- END */

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap named constructor !" << std::endl;
	defineHitPoints(100);
	defineEnergyPoints(50);
	defineAttackDamage(20);
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() == 0 || getHitPoints() <= 0)
		std::cout << "ScavTrap " << getName() << " is a little bit tired now, it can't attack !" << std::endl;
	else
	{
		defineEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attack " << target << ", causing " << getAttackDamage() << " points of damage !" << std::endl;
	}
}

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << getName() << " entered Gate keeper mode !" << std::endl;
}