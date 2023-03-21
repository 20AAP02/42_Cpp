#include <PmergeMe.hpp>

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1 || !(argv[1][0]))
			return PmergeMe().fterror("not enough arguments.");
		PmergeMe sequence(const_cast<const char**>(argv + 1));
		std::cout << sequence;
	}
	catch(const std::exception& e)
	{
	}
	return 0;
}