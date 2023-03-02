#include <easyfind.hpp>
#include <vector>

int main()
{
	std::vector<int> vec;

	for (int i = 1; i <= 5; i++)
        vec.push_back(i);
	::easyfind(vec, 0);
	return 0;
}