#pragma once
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	ScavTrap();
	ScavTrap(const ScavTrap &parent);
	ScavTrap operator=(const ScavTrap &parent);
	~ScavTrap();
};
