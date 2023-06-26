#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string value);
	~Zombie();

	void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);