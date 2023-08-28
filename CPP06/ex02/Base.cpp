#include "Base.hpp"

Base::~Base(void)
{
}

Base* Base::generate(void)
{
	std::srand(std::time(NULL));
	int number = std::rand();

	if (number % 3 == 0)
		return (new A);
	else if (number % 3 == 1)
		return (new B);
	else
		return (new C);
}

void Base::identify(Base* p)
{
	A *a = dynamic_cast<A*> (p);
	B *b = dynamic_cast<B*> (p);
	C *c = dynamic_cast<C*> (p);

	if (a != nullptr)
		std::cout << "The type is A" << std::endl;
	else if (b != nullptr)
		std::cout << "The type is B" << std::endl;
	else if (c != nullptr)
		std::cout << "The type is C" << std::endl;
}

void Base::identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&> (p);
		(void) a;
		std::cout << "The type is A" << std::endl;
	} catch (std::bad_cast &e) {}

	try {
		B &b = dynamic_cast<B&> (p);
		(void) b;
		std::cout << "The type is B" << std::endl;
	} catch (std::bad_cast &e) {}

	try {
		C &c = dynamic_cast<C&> (p);
		(void) c;
		std::cout << "The type is C" << std::endl;
	} catch (std::bad_cast &e) {}
}
