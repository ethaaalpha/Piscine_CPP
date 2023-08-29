#include "Base.hpp"

int main(void)
{
	Base base = Base();

	std::cout << "Test with random generator Base (a, b, c) :" << std::endl;
	Base *rand = base.generate();
	base.identify(rand);
	base.identify(rand);

	std::cout << std::endl << "Test with non random :" << std::endl;
	A a = A();
	B b = B();
	C c = C();
	base.identify(&a);
	base.identify(a);
	base.identify(&b);
	base.identify(b);
	base.identify(&c);
	base.identify(c);

	delete (rand);
	return 0;
}
