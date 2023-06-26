#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie constructor !" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor !" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	if (this->name == "Foo")
		std::cout << this->name << ": ";
	else
		std::cout << "<" << this->name << ">" << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
