#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "Intern: default constructor called\n";
}

Intern::Intern( const Intern & src )
{
	(void) src;
	std::cout << "Intern: copy constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "Intern: destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string stringToLower(const std::string strOriginal)
{
	std::string str = strOriginal;
	for (int index = 0; str[index]; index++)
		str[index] = (char)tolower(str[index]);
	return str;
}

std::string removeWhiteSpace(const std::string originalStr)
{
	std::string str;
	for (int i = 0; i < (int)originalStr.length(); i++)
		if (!isspace(originalStr[i]))
			str += originalStr[i];
	return str;
}

std::string translateTypeOfForm(const std::string formName)
{
	std::string name = stringToLower(formName);
	name = removeWhiteSpace(name);
	if (name != "shrubberycreation" && name != "robotomyrequest" && name != "presidentialpardon")
		return std::string("0");
	return name;
}

AForm *Intern::makeForm(const std::string formName, const std::string formTarget) const
{
	std::string formSimpleName = translateTypeOfForm(formName);
	switch (formSimpleName[0])
	{
		case 's':
			std::cout << "Intern creates shrubbery creation form\n";
			return new ShrubberyCreationForm(formTarget);
			break;
		case 'r':
			std::cout << "Intern creates robotomy request form\n";
			return new RobotomyRequestForm(formTarget);
			break;
		case 'p':
			std::cout << "Intern creates presidential pardon form\n";
			return new PresidentialPardonForm(formTarget);
			break;
		default:
			std::cout << "No existing form with the given name :(\n";
			return NULL;
			break;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */