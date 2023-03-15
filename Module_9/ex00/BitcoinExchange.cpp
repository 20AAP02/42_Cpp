#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	this->_dataBaseFileName = src._dataBaseFileName;
	this->_bitcoinPrices.insert(src._bitcoinPrices.begin(), src._bitcoinPrices.end());
}

BitcoinExchange::BitcoinExchange(const std::string dataBaseFileName)
{
	this->_dataBaseFileName = dataBaseFileName;
	this->readCsvFile(dataBaseFileName);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->_dataBaseFileName = rhs._dataBaseFileName;
		this->_bitcoinPrices.clear();
		this->_bitcoinPrices.insert(rhs._bitcoinPrices.begin(), rhs._bitcoinPrices.end());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{

	o << "Bitcoin prices were retrieved from " << i.getDataBaseFileName() << " file";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

float BitcoinExchange::valueOfBitcoin(const float amount, std::string date)
{
	if (this->_bitcoinPrices.find(date) != this->_bitcoinPrices.end())
		return (this->_bitcoinPrices[date] * amount);
	std::map<std::string, float>::iterator upperBound = this->_bitcoinPrices.lower_bound(date);
	std::map<std::string, float>::iterator lowerBound = upperBound;
	if (*upperBound == *(this->_bitcoinPrices.begin()))
		return (upperBound->second * amount);
	lowerBound--;
	if (*lowerBound == *(this->_bitcoinPrices.rbegin()))
		return (lowerBound->second * amount);
	return ((lowerBound->second + upperBound->second) / 2.0f) * amount;
}

void BitcoinExchange::readCsvFile(const std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file)
		throw BitcoinExchange::ErrorReadingDataBase();
	
	std::string args;
	std::string date;
	float exchange_rate = 0;
	int commaIndex = 0;
	while (file >> args)
	{
		while (args[commaIndex] != ',')
			commaIndex++;
		date = args.substr(0, commaIndex);
		if (commaIndex + 1 < (int)args.size())
			exchange_rate = atof(args.substr(commaIndex + 1, args.size() - commaIndex).c_str());
		else
			throw BitcoinExchange::ErrorReadingDataBase();
		this->_bitcoinPrices[date] = exchange_rate;
	}
	this->_bitcoinPrices.erase("date");
	file.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &BitcoinExchange::getDataBaseFileName() const
{
	return this->_dataBaseFileName;
}



/* ************************************************************************** */