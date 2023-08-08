#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();
	
public:
	FragTrap(const FragTrap &parent);
	FragTrap& operator=(const FragTrap &parent);
	~FragTrap();

	FragTrap(std::string name);
	void attack(const std::string& target);
	void highFivesGuys() const;
};
