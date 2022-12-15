#include <iostream>
#include <cctype>

char *str_upper(char *str)
{
	for (int index = 0; str[index]; index++)
		str[index] = (char)toupper(str[index]);
	return str;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int index = 1; index < argc; index++)
			std::cout << str_upper(argv[index]);
	std::cout << std::endl;
	return 0;
}