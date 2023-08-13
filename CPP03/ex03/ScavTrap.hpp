#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
public:
	ScavTrap();
	ScavTrap(const ScavTrap &parent);
	ScavTrap& operator=(const ScavTrap &parent);
	~ScavTrap();

	ScavTrap(std::string name);
	void attack(const std::string& target);
	void guardGate() const;
};


