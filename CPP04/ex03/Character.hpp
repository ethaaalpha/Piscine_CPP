#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];

public:
	Character(void);
	Character(const Character& parent);
	Character& operator=(const Character& parent);
	~Character(void);

	Character(std::string name);

	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};