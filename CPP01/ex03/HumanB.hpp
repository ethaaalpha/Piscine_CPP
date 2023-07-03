#ifndef HUMANB_CLASS_HPP
#define HUMANB_CLASS_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon* 	_weapon;
	std::string _name;
public:
	HumanB(std::string name);
	~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);
};
#endif