#ifndef CLAPTRAP_CLASS_HPP
#define CLAPTRAP_CLASS_HPP

#include <iostream>;

class ClapTrap
{
private:
	std::string _name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;
public:

	/* Canonical Form -- START */
	ClapTrap();
	ClapTrap(const ClapTrap &parent);
	ClapTrap& operator=(const ClapTrap &parent);
	~ClapTrap();



};

#endif