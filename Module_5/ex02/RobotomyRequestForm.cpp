#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "default";
	std::cout << "RobotomyRequestForm: default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): AForm(src)
{
	this->_target = src.getTarget();
	std::cout << "RobotomyRequestForm: copy constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm: constructor called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	std::cout << "RobotomyRequestForm: copy assignment called\n";
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
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

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void RobotomyRequestForm::func() const
{}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */