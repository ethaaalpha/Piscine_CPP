#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP
#include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string value);
	~Zombie();

	void	announce(void) const;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif