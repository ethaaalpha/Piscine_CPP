#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct = ClapTrap("Jesous");
	ct.attack("Alfred");
	ct.attack("Louis");
	ct.attack("Jean");
	ct.attack("Jacques");
	ct.attack("Timothe");

	ct.takeDamage(9);

	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);
	ct.beRepaired(1);

	ct.takeDamage(10);
	ct.beRepaired(1);
	ct.attack("Alfred");
	
	return 0;
}
