#include <easyfind.hpp>
#include <vector>
#include <list>
#include <map>
#include <iterator>

int main()
{
	{
		std::cout << "____Testing 'easyfind' with vector____\n";
		std::vector<int> vec;
		std::vector<int>::iterator ptr;

		vec.push_back( 4 );
		vec.push_back( 3 );
		vec.push_back( 5 );
		vec.push_back( 1 );
		vec.push_back( 6 );
		std::cout << "Created vector -> {";
		for (std::size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << ",";
		std::cout << "\b}\n";
		std::cout << "Try to find element '0': ";
		try
		{
			ptr = easyfind(vec, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Try to find element '3': ";
		ptr = easyfind(vec, 3);
		std::cout << *ptr << std::endl;
	}
	{
		std::cout << "____Testing 'easyfind' with list____\n";
		std::list<int> lst;
		std::list<int>::iterator ptr;

		lst.push_back( 4 );
		lst.push_back( 3 );
		lst.push_back( 5 );
		lst.push_back( 1 );
		lst.push_back( 6 );
		std::cout << "Created list -> (";
		for( std::list<int>::iterator iter= lst.begin(); iter != lst.end(); iter++ )
			std::cout << *iter << ",";
		std::cout << "\b)\n";
		std::cout << "Try to find element '-4': ";
		try
		{
			ptr = easyfind(lst, -4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Try to find element '5': ";
		ptr = easyfind(lst, 5);
		std::cout << *ptr << std::endl;	
	}
	return 0;
}