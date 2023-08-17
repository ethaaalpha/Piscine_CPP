#pragma once
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &parent);
	WrongAnimal& operator=(const WrongAnimal &parent);
	~WrongAnimal(void);

	std::string getType(void) const;
	void makeSound(void) const;
};