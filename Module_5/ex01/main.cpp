#include <Bureaucrat.hpp>

int main()
{
	try
	{
		std::cout << "--- Instantiation Tests (Too High) ---\n";
		Bureaucrat a("Jonh", 3);
		Bureaucrat b("jonhson", 1);
		Bureaucrat c("jonhson", 1);
		Bureaucrat d("jonhson", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << "--- Instantiation Tests (Too Low) ---\n";
		Bureaucrat a("Jonh", 50);
		Bureaucrat b("jonhson", 149);
		Bureaucrat c("jonhson", 150);
		Bureaucrat d("jonhson", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << "--- Value's Tests ---\n";
		Bureaucrat a("Jonh", 50);
		std::cout << a;
		Bureaucrat b("jonhson", 149);
		std::cout << "jonhson name: " << b.getName() << std::endl;
		std::cout << "jonhson grade: " << b.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "--- Incrementation Tests ---\n";
		Bureaucrat a("Jonh", 5);
		a.increment();
		a.increment();
		a.increment();
		a.increment();
		a.increment();
		a.increment();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	try
	{
		std::cout << "--- Decrementation Tests ---\n";
		Bureaucrat a("Jonh", 145);
		a.decrement();
		a.decrement();
		a.decrement();
		a.decrement();
		a.decrement();
		a.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
