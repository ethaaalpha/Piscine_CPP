#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	// With the virtual keyword so changing after compilation -> during runtime
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
    meta->makeSound();

	// Without the virtual keyword so decide at the compilation
	const WrongAnimal* Wmeta = new WrongAnimal();
	const WrongAnimal* Wi = new WrongCat();
	std::cout << Wi->getType() << " " << std::endl;
	Wi->makeSound(); 
    Wmeta->makeSound();

	delete (Wmeta);
	delete (Wi);
	delete (meta);
	delete (i);
	delete (j);
	return 0; 
}