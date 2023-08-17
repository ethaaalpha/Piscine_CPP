#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* _brain;
public:
	Cat(void);
	Cat(const Cat &parent);
	Cat& operator=(const Cat &parent);
	virtual ~Cat(void);
	
	virtual void makeSound(void) const;
	Brain* getBrain(void) const;
};
