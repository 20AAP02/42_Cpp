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

float BitcoinExchange::valueOfBitcoin(const float amount, const std::string date) const
{
	(void) amount;
	(void) date;
	return 0.0f;
}

void BitcoinExchange::readCsvFile(const std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file)
		throw BitcoinExchange::CantReadFileException();
	
	std::string date;
	float exchange_rate = 0;
	while (file >> date)
	{
		exchange_rate = atof(date.substr(date.find(',', 0) + 1).c_str());
		date = date.substr(0, date.find(',', 0));
		this->_bitcoinPrices[date] = exchange_rate;
	}
	std::cout << this->_bitcoinPrices["2011-04-02"] << std::endl;
	file.close();
	this->_bitcoinPrices.erase("date");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &BitcoinExchange::getDataBaseFileName() const
{
	return this->_dataBaseFileName;
}



/* ************************************************************************** */