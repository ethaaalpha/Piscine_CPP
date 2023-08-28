#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
public:
	virtual ~Base(void);

	Base *generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};