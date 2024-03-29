#include <iostream>
#include <string>
#include <Serializer.hpp>

int main()
{
	Serializer se;
	Data a;
	Data *b;
	uintptr_t ptr;

	a.school = 42;
	a.name = "Student";
	ptr = se.serialize(&a);
	b = se.deserialize(ptr);
	std::cout << "Data a: " << a.school << " " << a.name << std::endl;
	std::cout << "Data b: " << b->school << " " << b->name << std::endl;
	std::cout << "Adress of a: " << &a << std::endl;
	std::cout << "Adress of b: " << b << std::endl;
	if (b != &a)
		std::cout << "Incorrect\n";
	else
		std::cout << "Correct\n";
	return 0;
}