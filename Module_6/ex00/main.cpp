#include <iostream>
#include <string>
#include <ScalarConverter.hpp>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please give one, and only one, parameter as input\n";
		return 0;
	}
	ScalarConverter a(argv[1]);
	a.printValues();
	return 0;
}