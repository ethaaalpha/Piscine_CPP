#ifndef HUMANB_CLASS_HPP
#define HUMANB_CLASS_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon* weapon;
	std::string name;
public:
	HumanB(std::string name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &weapon);
};
#endif