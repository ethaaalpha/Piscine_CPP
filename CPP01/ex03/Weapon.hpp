#ifndef WEAPON_CLASS_HPP
#define WEAPON_CLASS_HPP
#include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon();

	const std::string& getType() const;
	void setType(std::string type);
};
#endif