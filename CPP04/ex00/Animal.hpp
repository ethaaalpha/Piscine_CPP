#pragma once
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal &parent);
	Animal& operator=(const Animal &parent);
	~Animal(void);

	std::string getType(void) const;
	virtual void makeSound(void) const;
};