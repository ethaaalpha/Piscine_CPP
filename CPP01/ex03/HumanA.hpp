#ifndef HUMANA_CLASS_HPP
#define HUMANA_CLASS_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon& 	_weapon;
	std::string _name;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void attack() const;
};
#endif