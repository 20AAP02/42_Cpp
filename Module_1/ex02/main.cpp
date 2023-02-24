#include <iostream>

int main()
{
	std::string sentence = "HI THIS IS BRAIN";
	std::string *stringPTR = &sentence;
	std::string &stringREF = sentence;

	std::cout << &sentence << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << sentence << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}