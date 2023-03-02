#include <Span.hpp>

int main()
{
	std::set<int> set;
	for (int i = 1234; i < 15000; i++)
		set.insert(i);
	Span a(20000);

	a.addNumber(4);
	a.addNumber(19);
	a.addNumber(345);
	a.addNumber(234);
	a.addNumber(12);
	a.addNumber(102);

	std::cout << "Span set: " << a << std::endl;
	std::cout << "Span size: " << a.getSize() << std::endl;
	std::cout << "Span shortest span: " << a.shortestSpan() << std::endl;
	std::cout << "Span longest span: " << a.longestSpan() << std::endl;

	std::cout << "\nWITH MORE NUMBERS NOW -----------------------------------------------------------------------\n";
	a.addNumbers(set.begin(), set.end());
	std::cout << "Span size: " << a.getSize() << std::endl;
	std::cout << "Span shortest span: " << a.shortestSpan() << std::endl;
	std::cout << "Span longest span: " << a.longestSpan() << std::endl;
	std::cout << "\nCheck if max limit is working -------------\n";
	try
	{
		std::cout << "Adding range between 15000 and 30000\n";
		set.clear();
		for (int i = 15000; i < 30000; i++)
			set.insert(i);
		a.addNumbers(set.begin(), set.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nSpan size: " << a.getSize() << std::endl;
	try
	{
		std::cout << "Adding the number 345698\n";
		a.addNumber(345698);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return 0;
}