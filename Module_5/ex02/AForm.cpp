#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(): name("default"), _rqdGradeToSgn(1), _rqdGradeToExc(1)
{
	this->_signed = false;
	std::cout << "AForm: default constructor called\n";
}

AForm::AForm(const std::string name, const int gradeSgn, const int gradeExc): name(name), _rqdGradeToSgn(gradeSgn), _rqdGradeToExc(gradeExc)
{
	this->testGrade(gradeSgn);
	this->testGrade(gradeExc);
	this->_signed = false;
	std::cout << "AForm: constructor called\n";
}

AForm::AForm( const AForm & src ): name(src.name), _rqdGradeToSgn(src.getRqdGradeToSgn()), _rqdGradeToExc(src.getRqdGradeToExc())
{
	this->_signed = src.isSigned();
	std::cout << "AForm: copy constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	std::cout << "AForm: deconstructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.isSigned();
	}
	std::cout << "AForm: copy assignment called\n";
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm " << i.getName() << " info:\n";
	o << "Signed: " << i.isSigned() << std::endl;
	o << "Required grade to sign: " << i.getRqdGradeToSgn() << std::endl;
	o << "Required grade to execute: " << i.getRqdGradeToExc() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string AForm::getName() const { return this->name; }

bool AForm::isSigned() const { return this->_signed; }

int AForm::getRqdGradeToSgn() const { return this->_rqdGradeToSgn; }

int AForm::getRqdGradeToExc() const { return this->_rqdGradeToExc; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_rqdGradeToSgn)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void AForm::testGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

/* ************************************************************************** */