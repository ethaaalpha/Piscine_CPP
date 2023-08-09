#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	DiamondTrap();
	std::string _name;

public:
	~DiamondTrap();
	DiamondTrap(DiamondTrap &parent);
	DiamondTrap& operator=(DiamondTrap &parent);

	DiamondTrap(std::string name);
	void attack(const std::string& target);
	void whoAmI();
};
