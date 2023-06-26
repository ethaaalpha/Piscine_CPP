#include <iostream>
#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP
class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	~Zombie();

	void	announce(void);
	void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
#endif