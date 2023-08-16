#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &parent);
	Cat& operator=(const Cat &parent);
	~Cat(void);
	
	virtual void makeSound(void) const;
};
