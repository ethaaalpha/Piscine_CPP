#include "Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(5, "Foo");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	
	horde[0].setName("Jean");
	horde[1].setName("Jacques");
	horde[2].setName("Jean-Jacques");
	horde[3].setName("Michel");
	horde[4].setName("Jeanne");

	std::cout << "Modified horde !" << std::endl;
	for (int i = 0; i < 5; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}
