#include <Span.hpp>

int main()
{
	std::set<int>::iterator ptr1;
	std::set<int>::iterator ptr2;
	Span a(6);

	a.addNumber(4);
	ptr1 = 5;
	*ptr2 = 24;
	a.addNumbers(ptr1, ptr2);
	return 0;
}