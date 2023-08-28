#include "Base.hpp"

int main(void)
{
	Base b = Base();

	A a = A();

	Base *rand = b.generate();
	b.identify(rand);
	b.identify(&a);
	delete (rand);
	return 0;
}
