#include "ClapTrap.hpp"

/* Canonical Form -- START */
ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(const ClapTrap &parent)
{
	_name = parent._name;
	_hit_points = parent._hit_points;
	_energy_points = parent._energy_points;
	_attack_damage = parent._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &parent)
{
	_name = parent._name;
	_hit_points = parent._hit_points;
	_energy_points = parent._energy_points;
	_attack_damage = parent._attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
}
/* Canonical Form -- END */