#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "---------- Constructors ------------\n";
	const Bureaucrat a("Joe", 1);
	const AForm *_a = new ShrubberyCreationForm("home");
	const AForm *_c = new RobotomyRequestForm("home");
	const AForm *_b = new PresidentialPardonForm("home");
	std::cout << "---------- Methods -----------------\n";
	_a->execute(a);
	std::cout << "---------- Destructors -------------\n";
	delete _a;
	delete _b;
	delete _c;
	return 0;
}
