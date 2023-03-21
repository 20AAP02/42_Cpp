#include <RPN.hpp>

int fterror(std::string message)
{
	std::cout << "Error " << message << std::endl;
	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 2 || !(argv[1][0]))
	{
		std::cout << "Error\n";
		return 1;
	}
	RPN a(argv[1]);
	return 0;
}