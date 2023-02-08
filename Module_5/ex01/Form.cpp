#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): name("default"), requiredGradeToSign(1), requiredGradeToExecute(1)
{
	this->_signed = false;
	std::cout << "Form: default constructor called\n";
}

Form::Form(const std::string name, const int requiredGradeToSign, int requiredGradeToExecute): name(name), requiredGradeToSign(requiredGradeToSign), requiredGradeToExecute(requiredGradeToExecute)
{
	this->_signed = false;
	std::cout << "Form: constructor called\n";
}

Form::Form( const Form & src ): name(src.getName()), requiredGradeToSign(src.getRequiredGradeToSign()), requiredGradeToExecute(src.getRequiredGradeToExecute())
{
	this->_signed = src.isSigned();
	std::cout << "Form: copy constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form: deconstructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.isSigned();
	}
	std::cout << "Form: copy assignment called\n";
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	//o << "Value = " << i.getValue();
	(void) i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */