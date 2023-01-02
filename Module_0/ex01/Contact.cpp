#include <Contact.hpp>

void print_contact_info(std::string str)
{
	std::cout << " ";
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ". |";
	else
	{
		int spaces = 10 - str.length();
		for (int i = 0; i < spaces; i++)
			std::cout << " ";
		std::cout << str;
	}
	std::cout << " |";
}

int Contact::display(int index)
{
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	std::cout << "|   Index    |    Name    |  Surname   |  Nickname  |" << std::endl;
	std::cout << "|------------|------------|------------|------------|" << std::endl;
	std::cout << "|          " << index << " |";
	print_contact_info(Contact::name);
	print_contact_info(Contact::surname);
	print_contact_info(Contact::nickname);
	std::cout << std::endl << "+------------+------------+------------+------------+" << std::endl;
}