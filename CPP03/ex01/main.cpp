#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap tp;
	tp.defineName("hello");
	std::cout << tp.getName() << std::endl;

	ScavTrap copy = ScavTrap(tp);
	std::cout << copy.getName() << std::endl;
	tp.defineName("Alfred");
	std::cout << tp.getName() << std::endl;
	copy = tp;
	std::cout << copy.getName() << std::endl;

	return 0;
}
