#pragma once
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap(const FragTrap &parent);
	FragTrap& operator=(const FragTrap &parent);
	~FragTrap();

	FragTrap(std::string name);
	void attack(const std::string& target);
	void highFivesGuys() const;
};
