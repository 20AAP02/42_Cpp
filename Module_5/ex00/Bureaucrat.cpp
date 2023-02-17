#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): name("NoName")
{
	this->grade = 150;
	std::cout << "Bureaucrat: " << this->name << ", called default constructor\n";
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): name(name)
{
	this->testGrade(grade);
	this->grade = grade;
	std::cout << "Bureaucrat: " << this->name << ", called constructor\n";
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): name(src.getName())
{
	this->grade = src.getGrade();
	std::cout << "Bureaucrat: " << this->name << ", called copy constructor\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: " << this->name << ", called destructor\n";
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

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ",  bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Bureaucrat::getName() const { return this->name; };

int Bureaucrat::getGrade() const { return this->grade; };

void Bureaucrat::increment()
{
	this->testGrade(this->grade - 1);
	this->grade -= 1;
	std::cout << "Bureaucrat: " << this->name << ", incremented level\n";

}

void Bureaucrat::decrement()
{
	this->testGrade(this->grade + 1);
	this->grade += 1;
	std::cout << "Bureaucrat: " << this->name << ", decremented level\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Bureaucrat::testGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

/* ************************************************************************** */