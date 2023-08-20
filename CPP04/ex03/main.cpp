#include "Character.hpp"
#include "Cure.hpp"

int main(void)
{
	AMateria* item = new Cure();
	AMateria* item1 = new Cure();
	AMateria* item2 = new Cure(item);
	AMateria* item3 = new Cure();
	Character alfred = Character("Alfred");
	alfred.equip(item);
	alfred.equip(item1);
	alfred.equip(item2);
	alfred.equip(item3);
	std::cout << alfred.getName() << std::endl;
	alfred.use(0, alfred);

	Character michel = Character(alfred);
	std::cout << michel.getName() << std::endl;
	michel.use(0, alfred);

	return 0;
}
