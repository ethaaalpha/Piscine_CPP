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
	this->_name = name;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
