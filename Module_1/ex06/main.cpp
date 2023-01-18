#include <Harl.hpp>

void complain(std::string level)
{
	Harl harl;
	switch (level[0])
	{
		case 'D':
			std::cout << "[ DEBUG ]\n";
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 'I':
			std::cout << "[ INFO ]\n";
			harl.complain("INFO");
			std::cout << std::endl;
		case 'W':
			std::cout << "[ WARNING ]\n";
			harl.complain("WARNING");
			std::cout << std::endl;
		case 'E':
			std::cout << "[ ERROR ]\n";
			harl.complain("ERROR");
			std::cout << std::endl;
	}
}

int main(int argc, char **argv)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	else if (argv[1] == levels[0] || argv[1] == levels[1] || argv[1] == levels[2] || argv[1] == levels[3])
		complain(argv[1]);
	else
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	return 0;
}