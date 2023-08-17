#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &parent);
	WrongCat& operator=(const WrongCat &parent);
	~WrongCat(void);
	
	void makeSound(void) const;
};
