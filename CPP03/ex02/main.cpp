#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag_1	= FragTrap("Alfred");
	FragTrap assignement_copy = frag_1;
	FragTrap parent_copy = FragTrap(assignement_copy);

	assignement_copy.defineName("Michel");
	std::cout << "-----------------FIGHT-----------------" << std::endl;
	assignement_copy.attack("Alfred");
	frag_1.takeDamage(30);
	assignement_copy.attack("Alfred");
	frag_1.takeDamage(30);
	frag_1.beRepaired(30);
	frag_1.attack("Michel");
	assignement_copy.takeDamage(30);
	frag_1.attack("Michel");
	assignement_copy.takeDamage(30);
	frag_1.attack("Michel");
	assignement_copy.takeDamage(30);
	frag_1.attack("Michel");
	assignement_copy.takeDamage(30);
	std::cout << "---------------------------------------" << std::endl;
	parent_copy.highFivesGuys();
	assignement_copy.highFivesGuys();
	frag_1.highFivesGuys();
}
