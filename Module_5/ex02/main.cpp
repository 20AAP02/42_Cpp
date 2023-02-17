#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	const AForm *a = new ShrubberyCreationForm("home");
	const AForm *c = new RobotomyRequestForm("home");
	const AForm *b = new PresidentialPardonForm("home");
	std::cout << "---------- Destructors -------------\n";
	delete a;
	delete b;
	delete c;
	return 0;
}
