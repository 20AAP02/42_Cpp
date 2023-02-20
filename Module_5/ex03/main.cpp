#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <Intern.hpp>

int main()
{
	std::cout << "---------- Constructors ------------\n";
	Intern someRandomIntern;
	AForm *a;
	AForm *b;
	AForm *c;
	AForm *d;
	AForm *e;
	AForm *f;
	AForm *g;

	std::cout << "---------- Methods -----------------\n";
	std::cout << "__Straight_Up_Names__ - That_Work\n";
	a = someRandomIntern.makeForm("robotomy request", "Jonh");
	b = someRandomIntern.makeForm("shrubbery creation", "garden");
	c = someRandomIntern.makeForm("presidential pardon", "albert");
	std::cout << "__Unordinary__Names__ - That_Work\n";
	d = someRandomIntern.makeForm("Robotomy Request	", "french");
	e = someRandomIntern.makeForm("PresidentialPardon", "hercules");
	std::cout << "__Incorrect_Names__\n";
	f = someRandomIntern.makeForm("robot request", "french");
	g = someRandomIntern.makeForm("shrubbery request", "french");
	std::cout << "\n And everynthing else still works...\n\n";
	std::cout << "___Test_Form's_Requisites___\n";
	std::cout << *a;
	std::cout << *b;
	std::cout << *c;
	std::cout << "And f, which should be Null. So 0...\n";
	std::cout << f;
	std::cout << std::endl;
	std::cout << "---------- Destructors -------------\n";
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	return 0;
}
