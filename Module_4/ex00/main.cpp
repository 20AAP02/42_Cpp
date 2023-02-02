#include <Animal.hpp>

int main()
{
	Animal a;
	a.setType("Dog");
	Animal *b = new Animal(a);
	std::cout << b->getType() << std::endl;
	delete b;
	return 0;
}