#include "ClapTrap.hpp"

/* Canonical Form -- START */
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &parent)
{
	std::cout << "ClapTrap parent constructor !" << std::endl;
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
	std::cout << "ClapTrap destructor !" << std::endl;
}
/* Canonical Form -- END */

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap named constructor !" << std::endl;
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy_points == 0 || _hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is a little bit tired now, it can't attack !" << std::endl;
	else
	{
		_energy_points -= 1;
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attack_damage << " points of damage !" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " took " << amount << " of damage !" << std::endl;
	if (amount >= _hit_points)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " is tired now, let it sleep !" << std::endl;
	}
	else
		_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points == 0 || _hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is a little bit tired now, it can't heal it self !" << std::endl;
	else
	{
		_energy_points -= 1;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " is healed of " << amount << " !" << std::endl;
		std::cout << "From now it got " << _hit_points << " hit points !" << std::endl;
	}
}

void ClapTrap::defineName(std::string new_name)
{
	_name = new_name;
}

void ClapTrap::defineEnergyPoints(unsigned int value)
{
	_energy_points = value;
}

void ClapTrap::defineLifePoints(unsigned int value)
{
	_hit_points = value;
}

void ClapTrap::defineAttackDamage(unsigned int value)
{
	_attack_damage = value;
}

std::string ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int ClapTrap::getLifePoints(void) const
{
	return (_hit_points);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (_attack_damage);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (_energy_points);
}