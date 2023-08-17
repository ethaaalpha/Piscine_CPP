#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
	Dog(void);
	Dog(const Dog &parent);
	Dog& operator=(const Dog &parent);
	virtual ~Dog(void);

	virtual void makeSound(void) const;
	Brain* getBrain(void) const;
};