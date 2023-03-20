#include <BitcoinExchange.hpp>
#include <filesystem>

int main(int argc, char **argv)
{
	BitcoinExchange a("data.csv");
	std::cout << a.valueOfBitcoin(5, "2011-04-02") << std::endl;
	return 0;
}