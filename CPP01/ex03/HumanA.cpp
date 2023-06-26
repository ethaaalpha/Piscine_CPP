#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name)
{
	std::cout << "HumanA " << this->name << " constructor !" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->name << " destructor !" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}