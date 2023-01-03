#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <Contact.hpp>

class PhoneBook
{
	Contact contacts[8];

public:
	int len(void);
	int oldest_contact_index(void);
	void open_phone_book(void);
	void add_contact(void);
	void search_contact(void);
	void clear_phone_book(void);
};


#endif