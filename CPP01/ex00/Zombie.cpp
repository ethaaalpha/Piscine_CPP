#include "Zombie.hpp"

Zombie::Zombie(std::string value) : name(value)
{
	std::cout << "Zombie constructor : " << value << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor : " << this->name << std::endl;
}

void	Zombie::announce(void)
{
	if (this->name == "Foo")
		std::cout << this->name << ": ";
	else
		std::cout << "<" << this->name << ">" << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
