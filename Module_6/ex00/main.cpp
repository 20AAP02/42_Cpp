#include <iostream>
#include <string>
#include <Literal.hpp>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please give one, and only one, parameter as input\n";
		return 0;
	}
	Literal a(argv[1]);
	a.printValues();
	return 0;
}