#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
# include <map>

class BitcoinExchange
{

	public:
		BitcoinExchange(const std::string dataBaseFileName);
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs ); 

		float valueOfBitcoin(const float amount, const std::string date) const;

		const std::string &getDataBaseFileName() const;

		class CantReadFileException : public std::exception {
			public: virtual const char* what() const throw() {
				return "BitcoinExchange error: count't open data base file!";
			}
		};

	private:
		std::string _dataBaseFileName;
		std::map<std::string, float> _bitcoinPrices;
		
		void readCsvFile(const std::string fileName);

		BitcoinExchange();


};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */