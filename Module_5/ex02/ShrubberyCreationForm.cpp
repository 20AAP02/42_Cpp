#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
	std::cout << "ShrubberyCreationForm: default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): AForm(src)
{
	this->_target = src.getTarget();
	std::cout << "ShrubberyCreationForm: copy constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm: constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	std::cout << "ShrubberyCreationForm: copy assignment called\n";
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << i.getName() << " info:\n";
	o << "Signed: " << i.isSigned() << std::endl;
	o << "Required grade to sign: " << i.getRqdGradeToSgn() << std::endl;
	o << "Required grade to execute: " << i.getRqdGradeToExc() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string ShrubberyCreationForm::getTarget() const { return this->_target; }

void ShrubberyCreationForm::func() const
{}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */