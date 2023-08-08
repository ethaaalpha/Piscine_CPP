#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav_a = ScavTrap("Louis");
	std::cout << "ScavTrap a: " << scav_a.getName() << std::endl;
	std::cout << std::endl;

	ScavTrap scav_b = ScavTrap("Alfred");
	std::cout << "ScavTrap b: " << scav_b.getName() << std::endl;
	std::cout << "Hitpoints : " << scav_b.getHitPoints() << std::endl;
	std::cout << "Energypoints : " << scav_b.getEnergyPoints() << std::endl;
	std::cout << "Attackdamage : " << scav_b.getAttackDamage() << std::endl << std::endl;

	std::cout << "ScavTrap a: " << scav_b.getName() << std::endl;
	scav_b = scav_a;
	std::cout << "ScavTrap a: " << scav_b.getName() << std::endl << std::endl;

	scav_a.guardGate();
	scav_b.guardGate();

	// to show that it inherite of the ClapTrap public attribute (depend of the mode )
	std::cout << std::endl;
	scav_a.attack("Michel");
	scav_b.beRepaired(10);
	scav_a.takeDamage(100);
	std::cout << std::endl;

}
