#include <iostream>
#include <string>
#include <iostream>
#include <sstream>

std::string getType(std::string arg)
{
	const std::string pseudoFloats[] = {"-inff", "+inff", "nanf"};
	const std::string pseudoDoubles[] = {"-inf", "+inf", "nan"};
	if (std::isdigit(arg[0]))
	{
		if (arg[arg.length() - 1] == 'f')
			return "float";
		if (arg.find(".") != arg.npos)
			return "double";
		return "int";
	}
	for (int i = 0; i < 3; i++)
		if (arg == pseudoFloats[i])
			return "floatP";
	for (int i = 0; i < 3; i++)
		if (arg == pseudoDoubles[i])
			return "doubleP";
	return "char";
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please give one, and only one, parameter as input\n";
		return 0;
	}
	std::string type = getType(argv[1]);
	std::cout << type << std::endl;


	// std::stringstream literal(argv[1]);
	// std::cout << "char: " << c << std::endl;
	// std::cout << "int: " << i << std::endl;
	// std::cout << "float: " << f << std::endl;
	// std::cout << "double: " << d << std::endl;
	return 0;
}