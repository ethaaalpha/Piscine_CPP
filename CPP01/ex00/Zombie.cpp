#include "Zombie.hpp"

Zombie::Zombie(std::string value) : _name(value)
{
	std::cout << "Zombie constructor : " << value << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor : " << this->_name << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
