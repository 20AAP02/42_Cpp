#include <RealType.hpp>

Base *generate(void)
{
	static int randomCheck;
	if (randomCheck == 0)
	{
		srand(time(0));
		randomCheck = 1;
	}
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
		case 2:
			newBase = new C();
			break;
	}
	return newBase;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "This object is of type A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "This object is of type B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "This object is of type C\n";
	else
		std::cout << "Thobject is of unknown type\n";
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "This object is of type A\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "This object is of type B\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "This object is of type C\n";
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Object is of unknown type\n";
	}
}