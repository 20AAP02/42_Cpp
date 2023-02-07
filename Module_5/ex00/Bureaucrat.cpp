#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): name("NoName")
{
	this->grade = 150;
	std::cout << "Bureaucrat: " << this->name << ", called constructor\n";
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): name(name)
{
	try
	{
		if (grade < 1)
			throw std::exception();
		else if (grade > 150)
			throw std::exception();
		else
			this->grade = grade;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Bureaucrat: " << this->name << ", called constructor\n";
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	this->grade = src.getGrade();
	std::cout << "Bureaucrat: " << this->name << ", called copy constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: " << this->name << ", called deconstructor\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->grade = rhs.getGrade();
		std::cout << "Bureaucrat: " << this->name << ", called copy assignment operator\n";
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Bureaucrat::getName() const { return this->name; };

int Bureaucrat::getGrade() const { return this->grade; };

void Bureaucrat::increment()
{	
}

void Bureaucrat::decrement()
{
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void testGrade(int grade)
{
	if (grade < 1)
		throw std::exception();
	else if (grade > 150)
		throw std::exception();
}

/* ************************************************************************** */