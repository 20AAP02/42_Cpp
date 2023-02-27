#include <iter.hpp>

void up(std::string &str)
{
	for (int i = 0; i < (int)str.length(); i++)
		str[i] = toupper(str[i]);
}

void addOne(int &i)
{
	i = i + 1;
}

void print(std::string &str)
{
	std::cout << str << std::endl;
}

int main()
{
	int intArr[] = {2, 4, 9, 1, 3};
	std::string stringArr[] = {"ola", "mundo"};
	::iter(stringArr, 2, up);
	::iter(intArr, 5, addOne);

	for (int i = 0; i < 5; i++)
	{
		if (i < 2)
		{
			std::cout << "stringArr " << i << ": " << stringArr[i];
			std::cout << " | ";
		}
		std::cout << "intArr " << i << ": " << intArr[i];
		std::cout << std::endl;
	}
	::iter(stringArr, 2, print);

	return 0;
}
