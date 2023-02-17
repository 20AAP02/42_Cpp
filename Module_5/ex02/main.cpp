#include <Bureaucrat.hpp>
#include <AForm.hpp>


int main()
{
	try
	{
		Bureaucrat a("A", 30);
		Bureaucrat b("B", 38);
		Bureaucrat c("C", 104);
		Bureaucrat d("D", 15);
		Bureaucrat e("E", 54);
		Bureaucrat f("F", 4);

		AForm _a("1", 34, 20);
		AForm _b("2", 80, 23);
		AForm _c("3", 14, 105);
		AForm _d("4", 15, 23);
		AForm _e("5", 67, 1);
		AForm _f("6", 46, 3);

		a.signForm(_a);
		b.signForm(_b);
		c.signForm(_c);
		d.signForm(_d);
		e.signForm(_e);
		f.signForm(_f);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// test low sign
	try
	{
		AForm _a("1", 154, 20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// test high execute
	try
	{
		AForm _e("5", 67, -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// test high sign
	try
	{
		AForm _a("1", -10, 20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// test low execute
	try
	{
		AForm _e("5", 67, 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
