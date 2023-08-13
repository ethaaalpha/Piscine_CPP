#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;

public:
	DiamondTrap(void);
	~DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &parent);
	DiamondTrap& operator=(const DiamondTrap &parent);

	std::string getDiamondName(void);

	void attack(const std::string& target);
	void whoAmI();
};
