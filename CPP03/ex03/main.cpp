#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond = DiamondTrap("Alfred");
	std::cout << std::endl << "** Alfred the DiamondTrap **" << std::endl;
	std::cout << "* Name : " << diamond.getName() << std::endl;
	std::cout << "* Diamond Name : " << diamond.getDiamondName() << std::endl;
	std::cout << "* Attack Damage : " << diamond.getAttackDamage() << std::endl;
	std::cout << "* Hit Points : " << diamond.getHitPoints() << std::endl;
	std::cout << "* Energy Points : " << diamond.getEnergyPoints() << std::endl;
	std::cout << "**                        **" << std::endl << std::endl;

	FragTrap frag = FragTrap("Hercule");
	ScavTrap scav = ScavTrap("Corinthe");

	std::cout << std::endl << "* Tests *" << std::endl;
	if (50 == diamond.getEnergyPoints())
		std::cout << "EnergyPoints equality for ScavTrap and DiamondTrap" << std::endl;
	if (30 == diamond.getAttackDamage())
		std::cout << "AttackDamage equality for FragTrap and DiamondTrap" << std::endl;

	std::cout << std::endl << "* Capacities *" << std::endl;
	scav.attack("Michelle");
	diamond.attack("Michelle");
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();
	std::cout << std::endl;
	
}
