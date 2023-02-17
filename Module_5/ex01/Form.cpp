#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): name("default"), _rqdGradeToSgn(1), _rqdGradeToExc(1)
{
	this->_signed = false;
	std::cout << "Form: default constructor called\n";
}

Form::Form(const std::string name, const int gradeSgn, const int gradeExc): name(name), _rqdGradeToSgn(gradeSgn), _rqdGradeToExc(gradeExc)
{
	this->testGrade(gradeSgn);
	this->testGrade(gradeExc);
	this->_signed = false;
	std::cout << "Form: constructor called\n";
}

Form::Form( const Form & src ): name(src.name), _rqdGradeToSgn(src.getRqdGradeToSgn()), _rqdGradeToExc(src.getRqdGradeToExc())
{
	this->_signed = src.isSigned();
	std::cout << "Form: copy constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form: destructor called\n";
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
	o << "Form " << i.getName() << " info:\n";
	o << "Signed: " << i.isSigned() << std::endl;
	o << "Required grade to sign: " << i.getRqdGradeToSgn() << std::endl;
	o << "Required grade to execute: " << i.getRqdGradeToExc() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Form::getName() const { return this->name; }

bool Form::isSigned() const { return this->_signed; }

int Form::getRqdGradeToSgn() const { return this->_rqdGradeToSgn; }

int Form::getRqdGradeToExc() const { return this->_rqdGradeToExc; }

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_rqdGradeToSgn)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Form::testGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

/* ************************************************************************** */