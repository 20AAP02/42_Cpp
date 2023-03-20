#include <BitcoinExchange.hpp>

int main()
{
	BitcoinExchange a("data.csv");
	std::cout << a.valueOfBitcoin(5, "2011-04-02") << std::endl;
	return 0;
}