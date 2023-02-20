#include <Bureaucrat.hpp>
#include <Form.hpp>


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
		std::cout << f;

		Form _a("1", 34, 20);
		Form _b("2", 80, 23);
		Form _c("3", 14, 105);
		Form _d("4", 15, 23);
		Form _e("5", 67, 1);
		Form _f("6", 46, 3);
		std::cout << _a;

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
		Form _a("1", 154, 20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// test high execute
	try
	{
		Form _e("5", 67, -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// test high sign
	try
	{
		Form _a("1", -10, 20);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// test low execute
	try
	{
		Form _e("5", 67, 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
