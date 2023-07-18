#ifndef CLAPTRAP_CLASS_HPP
#define CLAPTRAP_CLASS_HPP

#include <iostream>

class ClapTrap
{
private:
	ClapTrap();
	std::string 	_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &parent);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap &parent);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif