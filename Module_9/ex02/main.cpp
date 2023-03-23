#include <PmergeMe.hpp>

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1 || !(argv[1][0]))
			return PmergeMe().fterror("not enough arguments.");
		PmergeMe sequence(const_cast<const char**>(argv + 1));
		std::string lstTime = sequence.sortList();
		std::string vctTime = sequence.sortVector();
		std::cout << sequence << lstTime << vctTime;
		
	}
	catch(const std::exception& e)
	{
	}
	return 0;
}