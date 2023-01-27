#include <Point.hpp>

int main()
{
	Point a(2.0f, 2.0f);
	Point b(4.0f, 2.0f);
	Point c(3.0f, 4.0f);

	Point d(3.0f, 3.0f);
	std::cout << bsp(a, b, c, d) << std::endl;
	return 0;
}
