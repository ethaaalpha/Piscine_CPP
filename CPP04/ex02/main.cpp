#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;

	AAnimal *animals[4];
	animals[0] = new Cat();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Dog();

	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	
	for (int i = 0; i < 4; i++)
		delete animals[i];


	Cat cat = Cat();
	std::cout << std::endl << "Les idées du chat :" << std::endl; 
	cat.getBrain()->setIdea("Une idée vraiment incroyable", 0);
	cat.getBrain()->setIdea("Une seconde idée vraiment incroyable", 1);
	cat.getBrain()->setIdea("Une troisième idée vraiment incroyable", 99);
	cat.getBrain()->printIdeas();
	std::cout << std::endl;

	Cat cat_copy = cat;
	std::cout << std::endl << "Les idées du chat copié :" << std::endl; 
	cat.getBrain()->printIdeas();
	std::cout << std::endl;

	cat.getBrain()->setIdea("Une idée pas si incroyable" , 0);
	cat.getBrain()->setIdea("Une seconde idée désastreuse", 1);
	cat.getBrain()->setIdea("Une troisième idée catastrophique", 99);
	cat_copy.getBrain()->setIdea("Une quatrième idée incroyable", 4);
	cat_copy.getBrain()->setIdea("Une cinquième idée incroyable", 5);

	std::cout << std::endl << "Les idées du chat :" << std::endl;
	cat.getBrain()->printIdeas();

	std::cout << std::endl << "Les idées du chat copié :" << std::endl;
	cat_copy.getBrain()->printIdeas();  

	return 0;
}
