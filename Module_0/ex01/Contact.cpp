#include <Contact.hpp>

void print_contact_info(std::string str)
{
	std::cout << " ";
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		int spaces = 10 - str.length();
		for (int i = 0; i < spaces; i++)
			std::cout << " ";
		std::cout << str;
	}
	std::cout << " |";
}

void Contact::print_detailed_info(void)
{
	std::cout << "Creation Date: ";
	// sec, min, hour
	std::cout << Contact::localTime.tm_hour << ":" << Contact::localTime.tm_min << ":" << Contact::localTime.tm_sec;
	// day, month, year
	std::cout << " " << Contact::localTime.tm_mday << "/" << Contact::localTime.tm_mon + 1 << "/" << Contact::localTime.tm_year;
	std::cout << std::endl;
	std::cout << "Name: " << Contact::name << std::endl;
	std::cout << "Surname: " << Contact::surname << std::endl;
	std::cout << "Nickname: " << Contact::nickname << std::endl;
	std::cout << "Phone Number: " << Contact::phone_number << std::endl;
	std::cout << "Darkest Secret: " << Contact::darkest_secret << std::endl;
}

int Contact::check_input(std::string str)
{
	if (str.find_first_not_of(" \t\n\v\f\r") == str.npos)
	{
		Contact::clear_contact();
		return ERROR;
	}
	return DONE;
}

void Contact::display(int index)
{
	std::cout << "|          " << index << " |";
	print_contact_info(Contact::name);
	print_contact_info(Contact::surname);
	print_contact_info(Contact::nickname);
	std::cout << std::endl << "+------------+------------+------------+------------+" << std::endl;
}

void copy_time(struct tm *a, struct tm *b)
{
	a->tm_sec = b->tm_sec;
	a->tm_min = b->tm_min;
	a->tm_hour = b->tm_hour;
	a->tm_mday = b->tm_mday;
	a->tm_mon = b->tm_mon;
	a->tm_year = b->tm_year;
}

int Contact::get_contact_info(void)
{
	time_t currentTime;

	std::cout << "NEW CONTACT" << std::endl;

	// Get name
	std::cout << "Name: ";
	std::getline(std::cin, Contact::name);
	if (Contact::check_input(Contact::name))
		return ERROR;

	// Get Surname
	std::cout << "Surname: ";
	std::getline(std::cin, Contact::surname);
	if (Contact::check_input(Contact::surname))
		return ERROR;

	// Get Nickname
	std::cout << "Nickname: ";
	std::getline(std::cin, Contact::nickname);
	if (Contact::check_input(Contact::nickname))
		return ERROR;

	// Get Phone Number
	std::cout << "Phone Number: ";
	std::getline(std::cin, Contact::phone_number);
	if (Contact::check_input(Contact::phone_number))
		return ERROR;

	// Get Darkest Secret
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, Contact::darkest_secret);
	if (Contact::check_input(Contact::darkest_secret))
		return ERROR;
	time(&currentTime);
	copy_time(&(Contact::localTime), localtime(&currentTime));
	return DONE;
}

void Contact::clear_contact(void)
{
	Contact::name.clear();
	Contact::surname.clear();
	Contact::nickname.clear();
	Contact::phone_number.clear();
	Contact::darkest_secret.clear();
}

int Contact::contact_empty(void)
{
	return Contact::check_input(Contact::name);
}
