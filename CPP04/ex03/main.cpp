#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	std::cout << "Character & Copy test" << std::endl;
	Character alfred = Character("Alfred");
	alfred.equip(new Ice());
	alfred.equip(new Cure());

	Character michel = Character("Michel");
	michel.equip(new Cure());
	michel.equip(new Ice());
	michel.use(0, alfred);
	michel.use(1, alfred);

	std::cout << std::endl;
	Character copy = Character(michel);
	std::cout << copy.getName() << std::endl;
	copy.use(1, alfred);

	std::cout << std::endl << "Memory test" << std::endl;

	IMateriaSource* memorySource = new MateriaSource();
	memorySource->learnMateria(ice);
	memorySource->learnMateria(cure);
	memorySource->learnMateria(ice);
	memorySource->learnMateria(cure);

	AMateria* adresssave[2]; // to save item that are gonna to be throwed on the floor
	adresssave[0] = memorySource->createMateria("ice");
	adresssave[1] = memorySource->createMateria("cure");
	alfred.equip(adresssave[0]);
	alfred.equip(adresssave[1]);

	// have to do nothing
	michel.use(4, alfred);
	michel.use(3, alfred);
	michel.use(2, alfred);
	michel.use(-1, alfred);
	memorySource->createMateria("fire");

	std::cout << std::endl << "Unequip & Equip test" << std::endl;
	alfred.unequip(65);
	alfred.unequip(-65);
	alfred.unequip(2);
	alfred.unequip(3);
	michel.equip(adresssave[0]);
	michel.unequip(2);
	
	std::cout << std::endl << "Use test" << std::endl;
	michel.use(0, alfred);
	michel.use(1, alfred);
	alfred.use(0, michel);
	alfred.use(1, michel);
	
	delete (memorySource);
	delete (cure);
	delete (ice);
	delete (adresssave[0]);
	delete (adresssave[1]);


	return 0;
}