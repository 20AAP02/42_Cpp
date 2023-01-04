#ifndef CONTACT_HPP
# define CONTACT_HPP

# define ERROR 1
# define DONE 0

# include <iostream>
# include <cctype>
# include <string>
# include <bits/stdc++.h>
# include <unistd.h>

class Contact
{
	std::string name, surname, nickname;
	std::string phone_number, darkest_secret;

public:
	struct tm localTime;
	int check_input(std::string str);
	int	contact_empty(void);
	void display(int index);
	int	get_contact_info(void);
	void clear_contact(void);
	void print_detailed_info(void);
};

#endif