#include <RealType.hpp>

Base *generate(void);
{
	Base * newBase;
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			newBase = new A();
			break;
		case 1:
			newBase = new B();
			break;
		
		default:
			newBase = new C();
			break;
	}
	return newBase;
}

void identify(Base *p)
{
}

void identify(Base &p)
{
}