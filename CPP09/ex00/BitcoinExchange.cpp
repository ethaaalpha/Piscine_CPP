#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& parent) { *this = parent;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& parent)
{
	(void) parent;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::fillHistoricValues(const char *filename)
{
	std::ifstream 	ifs(filename);
	std::string		key;
	std::string		value;
	
	if (ifs.fail())
		throw (FileErrorException());
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!ifs.eof())
	{
		std::getline(ifs, key, ',');
		std::getline(ifs, value, '\n');
		_historicValues.insert(std::pair<std::string, std::string>(key, value));
	}
}
