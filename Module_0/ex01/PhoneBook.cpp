#include <PhoneBook.hpp>

// return 0 if the oldest is the first arg | return 1 if the not
// return 2 if it's the same time
int compare_time(struct tm *a, struct tm *b)
{
	if (a->tm_year != b->tm_year)
		return (a->tm_year > b->tm_year);
	if (a->tm_mon != b->tm_mon)
		return (a->tm_mon > b->tm_mon);
	if (a->tm_mday != b->tm_mday)
		return (a->tm_mday > b->tm_mday);
	if (a->tm_hour != b->tm_hour)
		return (a->tm_hour > b->tm_hour);
	if (a->tm_min != b->tm_min)
		return (a->tm_min > b->tm_min);
	if (a->tm_sec != b->tm_sec)
		return (a->tm_sec > b->tm_sec);
	return 2;
}

int PhoneBook::oldest_contact_index(void)
{
	time_t currentTime;
	struct tm *oldest_time;
	int respective_index;

	time(&currentTime);
  	oldest_time = localtime(&currentTime);
	respective_index = 0;
	for (int i = 0; i < 8; i++)
	{
		if (PhoneBook::contacts[i].contact_empty() && !i)
			return -1;
		if (PhoneBook::contacts[i].contact_empty())
			break;
		if (compare_time(oldest_time, PhoneBook::contacts[i].localTime))
		{
			oldest_time = PhoneBook::contacts[i].localTime;
			respective_index = i;
		}
	}
	return (respective_index);
}

int PhoneBook::len(void)
{
	for (int index = 0; index < 8; index++)
		if (PhoneBook::contacts[index].contact_empty())
			return index;
	return 8;
}

void PhoneBook::open_phone_book(void)
{
	std::string command;

	system("clear");
	std::cout << "-> ";
	while (1)
	{
		if (!command.empty())
			std::cout << "-> ";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
		{
			PhoneBook::add_contact();
		}
		else if (!command.compare("SEARCH")) 
		{
			PhoneBook::search_contact();
		}
		else if (!command.compare("EXIT"))
		{
			PhoneBook::clear_phone_book();
			break;
		}
		else if (!command.empty())
		{
			// system("clear");
			std::cout << "Invalid Command!\nPlease use one of this commands:\n ADD";
			std::cout << " (Add New Contact)\n SEARCH (Search Contact by Index)\n EXIT (Exit Phone Book)";
			std::cout << std::endl;
		}
	}
}

void PhoneBook::add_contact(void)
{
	Contact contact;
	int	index = PhoneBook::len();

	// system("clear");
	if (contact.get_contact_info())
	{
		std::cout << "Field can not be left empty!" << std::endl;
	}
	else if (index == 8)
	{
		index = PhoneBook::oldest_contact_index();
		PhoneBook::contacts[index] = contact;
		std::cout << "Contact Added" << std::endl;
	}
	else
	{
		PhoneBook::contacts[index] = contact;
		std::cout << "Contact Added" << std::endl;
	}
}

void PhoneBook::search_contact(void)
{
	int index;

	// system("clear");
	if (PhoneBook::len() == 0)
	{
		std::cout << "No Contacts on Phone Book...\n";
		return ;
	}
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	std::cout << "|   Index    |    Name    |  Surname   |  Nickname  |" << std::endl;
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (i >= PhoneBook::len())
			break;
		PhoneBook::contacts[i].display(i);
	}
	std::cout << "\nINDEX: ";
	std::cin >> index;
	// system("clear");
	if (index >= 8 || PhoneBook::contacts[index].contact_empty())
	{
		std::cout << "Invalid Index" << std::endl;
	}
	else
		PhoneBook::contacts[index].print_detailed_info();
}

void PhoneBook::clear_phone_book(void)
{
	// system("clear");
	for (int i = 0; i < 8; i++)
		PhoneBook::contacts[i].clear_contact();
}