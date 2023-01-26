#include <Fixed.hpp>

int main()
{
	Fixed a(10.5f);
	std::cout << a.toInt() << std::endl;
	return 0;
}
