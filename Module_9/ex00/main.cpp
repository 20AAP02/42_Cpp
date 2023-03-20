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
		std::stringstream str(line);
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
		if (counter < 2)
			fterror("bad input => " + line);
		else
		{
			float amount = atof(value.c_str());
			if (amount < 0.0f)
				fterror("not a positive number.");
			else if (amount > 1000.0f)
				fterror("too large a number.");
			else
			{
				if (date == "date")
					continue;
				std::string datePart;
				int year, month, day;
				std::stringstream wrd(date);
				counter = 0;
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
				if (year < 0 || year > 2023 || month < 0 || month > 11 || day < 0 || day > 31)
					fterror("bad input => " + date);
				else
				{
					std::cout << date << " => " << amount << " = ";
					std::cout << BitcoinDataBase.valueOfBitcoin(amount, date) << std::endl;
				}
			}
			
		}
	}
	file.close();
	return 0;
}