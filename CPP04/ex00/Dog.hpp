#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &parent);
	Dog& operator=(const Dog &parent);
	~Dog(void);

	virtual void makeSound(void) const;
};