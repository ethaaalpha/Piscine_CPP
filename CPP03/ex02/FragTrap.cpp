#include "FragTrap.hpp"

/* Canonical Form -- START */
FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor !" << std::endl;
}

FragTrap::FragTrap(const FragTrap &parent) : ClapTrap(parent)
{
	std::cout << "FragTrap parent constructor !" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &parent)
{
	defineName(parent.getName());
	defineEnergyPoints(parent.getEnergyPoints());
	defineHitPoints(parent.getHitPoints());
	defineAttackDamage(parent.getAttackDamage());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap deconstructor !" << std::endl;
}
/* Canonical Form -- END */

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap named constructor !" << std::endl;
	defineHitPoints(100);
	defineEnergyPoints(100);
	defineAttackDamage(30);
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << getName() << " asked for a high fives !" << std::endl;
}