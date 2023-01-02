#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cctype>
# include <string>

class Contact
{
	std::string name, surname, nickname;
	std::string phone_number, darkest_secret;

public:
	int display(int index);
};

#endif