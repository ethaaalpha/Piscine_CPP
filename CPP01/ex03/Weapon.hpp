#ifndef WEAPON_CLASS_HPP
#define WEAPON_CLASS_HPP
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	~Weapon();

	std::string getType() const;
	void		setType(std::string type);
};
#endif