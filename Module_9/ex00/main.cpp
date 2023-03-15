#include <BitcoinExchange.hpp>
#include <filesystem>

int main(int argc, char **argv)
{
	if (argc != 2 || std::filesystem::exists(argv[1]))
	BitcoinExchange a("data.csv");
	return 0;
}