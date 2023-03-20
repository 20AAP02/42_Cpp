#include <BitcoinExchange.hpp>
#include <filesystem>

int main()
{
	BitcoinExchange a("data.csv");
	std::cout << a.valueOfBitcoin(1, "2011-04-02") << std::endl;
	return 0;
}