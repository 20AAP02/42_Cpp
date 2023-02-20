#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "---------- Constructors ------------\n";
	const Bureaucrat a("Joe", 1);
	const Bureaucrat b("Jonh", 50);
	AForm *_a = new ShrubberyCreationForm("home");
	AForm *_b = new PresidentialPardonForm("Jonh");
	AForm *_c = new RobotomyRequestForm("Albert");
	std::cout << "---------- Methods -----------------\n";

	a.executeForm(*_a);
	a.signForm(*_a);
	b.executeForm(*_a);
	b.signForm(*_c);

	std::cout << "---------- Destructors -------------\n";
	delete _a;
	delete _b;
	delete _c;
	return 0;
}
