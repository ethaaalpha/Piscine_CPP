#pragma once
#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(const AAnimal &parent);
	AAnimal& operator=(const AAnimal &parent);
	virtual ~AAnimal(void) = 0;

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
};