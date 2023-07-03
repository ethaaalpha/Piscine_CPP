#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name)
{
	std::cout << "HumanA " << this->_name << " constructor !" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->_name << " destructor !" << std::endl;
}

void	HumanA::attack() const 
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}