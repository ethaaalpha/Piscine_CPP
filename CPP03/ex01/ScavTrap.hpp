#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();
	
public:
	ScavTrap(const ScavTrap &parent);
	ScavTrap& operator=(const ScavTrap &parent);
	~ScavTrap();


	ScavTrap(std::string name);
	void attack(const std::string& target);
	void guardGate() const;
};
