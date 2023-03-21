#include <BitcoinExchange.hpp>
#include <sstream>

bool fileExists(const char *fileName)
{
	std::ifstream f(fileName);
	return f.good();
}

int fterror(std::string message)
{
	std::cout << "Error: " << message << std::endl;
	return 1;
}

int getDateAndValue(const std::string line, std::string &date, std::string &value)
{
	std::stringstream str(line);
	std::string word;
	int counter = 0;
	while (getline(str, word, '|'))
	{
		word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
		if (!counter)
			date = word;
		else
			value = word;
		counter++;
	}
	return counter;
}

void divideDate(const std::string date, int &year, int &month, int &day)
{
	std::string datePart;
	std::stringstream wrd(date);
	int counter = 0;
	while(getline(wrd, datePart, '-'))
	{
		if (!counter)
			year = atoi(datePart.c_str());
		else if (counter == 1)
			month = atoi(datePart.c_str());
		else
			day = atoi(datePart.c_str());
		counter++;
	}
}

void printBitcoinValue(BitcoinExchange &BitcoinDataBase, const std::string date, const float amount)
{
	if (date == "date")
		return;
	int year, month, day;
	divideDate(date, year, month, day);
	if (year < 0 || year > 2023 || month < 0 || month > 11 || day < 0 || day > 31)
		fterror("bad input => " + date);
	else
	{
		std::cout << date << " => " << amount << " = ";
		std::cout << BitcoinDataBase.valueOfBitcoin(amount, date) << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || fileExists(argv[1]) == false)
		return fterror("could not open file.");
	BitcoinExchange BitcoinDataBase("data.csv");
	std::ifstream file(argv[1]);
	if (!file)
		return fterror("could not open file.");
	std::string line, word, date, value;
	while (getline(file, line))
	{
		if (getDateAndValue(line, date, value) < 2)
			fterror("bad input => " + line);
		else
		{
			float amount = atof(value.c_str());
			if (amount < 0.0f)
				fterror("not a positive number.");
			else if (amount > 1000.0f)
				fterror("too large a number.");
			else
				printBitcoinValue(BitcoinDataBase, date, amount);
			
		}
	}
	file.close();
	return 0;
}