#include "Zombie.hpp"

int main(void)
{
	Zombie *zomb_heap = newZombie("Alfred"); //made on heap
	zomb_heap->announce();
	randomChump("Foo"); //made on stack;
	zomb_heap->announce();
	zomb_heap->announce();
	zomb_heap->announce();
	zomb_heap->announce();

	delete(zomb_heap);
	return 0;
}
