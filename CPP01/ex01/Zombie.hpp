#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

#include <iostream>
class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	~Zombie();

	void	announce(void) const;
	void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
#endif