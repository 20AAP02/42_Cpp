#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main()
{
	std::cout << "---------- Constructors ------------\n";
	Bureaucrat a("Joe", 1);
	Bureaucrat b("Jonh", 50);
	Bureaucrat c("Jonathan", 149);
	AForm *_a = new ShrubberyCreationForm("home");
	AForm *_b = new RobotomyRequestForm("Jonh");
	AForm *_c = new PresidentialPardonForm("Albert");
	std::cout << "---------- Methods -----------------\n";
	std::cout << "___Test_Form's_Requisites___\n";
	std::cout << *_a;
	std::cout << *_b;
	std::cout << *_c;
	std::cout << std::endl;
	std::cout << "----------> Shrubbery Creation Form <----------\n";
	std::cout << "___Unsingned_Form___\n";
	a.executeForm(*_a);
	c.signForm(*_a);
	b.signForm(*_a);
	std::cout << "___Signed_Form___\n";
	c.executeForm(*_a);
	b.executeForm(*_a);
	a.executeForm(*_a);
	std::cout << std::endl;
	std::cout << "----------> Robotomy Request Form <----------\n";
	std::cout << "___Unsingned_Form___\n";
	a.executeForm(*_b);
	c.signForm(*_b);
	b.signForm(*_b);
	std::cout << "___Signed_Form___\n";
	c.executeForm(*_b);
	b.executeForm(*_b);
	a.executeForm(*_b);
	std::cout << "___Check_50%_percent_chance___\n";
	a.executeForm(*_b);
	a.executeForm(*_b);
	a.executeForm(*_b);
	std::cout << std::endl;
	std::cout << "----------> Presidential Pardon Form <----------\n";
	std::cout << "___Unsingned_Form___\n";
	a.executeForm(*_c);
	c.signForm(*_c);
	b.signForm(*_c);
	a.signForm(*_c);
	std::cout << "___Signed_Form___\n";
	c.executeForm(*_c);
	b.executeForm(*_c);
	a.executeForm(*_c);
	std::cout << "---------- Destructors -------------\n";
	delete _c;
	delete _b;
	delete _a;
	return 0;
}
