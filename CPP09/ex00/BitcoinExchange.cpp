#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& parent) { *this = parent;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& parent)
{
	(void) parent;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void	BitcoinExchange::doAnalyse(char const *input)
{
	try {
		fillHistoricValues();
		doInputValues(input);
	} catch (std::exception &e) {
		std::cout << "An error occured : " << e.what() << std::endl;
		std::exit(1);
	}
}

void	BitcoinExchange::fillHistoricValues(void)
{
	std::ifstream 	ifs("data.csv");
	std::string		key;
	std::string		value;
	
	if (ifs.fail())
		throw (FileErrorException());
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!ifs.eof())
	{
		std::getline(ifs, key, ',');
		std::getline(ifs, value, '\n');
		_historicValues.insert(std::pair<std::string, float>(key, ft_stof(value)));
	}
}

void 	BitcoinExchange::doInputValues(const char *filename)
{
	std::ifstream 	ifs(filename);
	std::string 	buffer;


	if (ifs.fail())
		throw (FileErrorException());
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (ifs.eof())
		throw (FileEmptyException());
	while (!ifs.eof())
	{
		std::getline(ifs, buffer, '\n');
		if (buffer.empty())
			continue ;
		try {
			getAnalyseLine(buffer);
		} catch (std::exception &e) {
			std::cout << "Error : " << e.what() << std::endl; 
		}
	}
}

// 2011-01-03 | 3

void BitcoinExchange::treatDate(std::string date)
{
	int 	year, month, day;

	date.resize(10);
	if (date.at(4) != '-' || date.at(7) != '-')
		throw (InvalidCharacterException());

	std::replace(date.begin(), date.end(), '-', '0');
	if (date.find_first_not_of("0123456789") != std::string::npos)
		throw (InvalidCharacterException());
	date.replace(4, 1, "-");
	date.replace(7, 1, "-");

	const char *str = date.c_str();
	year = std::atoi(str);
	month = std::atoi(str + 5);
	day = std::atoi(str + 8);
	if (month == 0 || month > 12 || day == 0 || day > 31)
		throw (InvalidCalendarException());
	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		throw (EarlyDateException());
}

float BitcoinExchange::treatValue(std::string value)
{
	value.erase(value.begin(), value.begin() + 13);

	if (value.find_first_not_of("0123456789.") != std::string::npos || std::count(value.begin(), value.end(), '.') > 1 || *(value.end() - 1) == '.')
		throw (InvalidCharacterException());

	double d_value = ft_stof(value);
	if (d_value > std::numeric_limits<float>::max() || d_value < 0 || d_value > 1000)
		throw (InvalidNumberException());
	return (d_value);
}

void	BitcoinExchange::getAnalyseLine(std::string line)
{
	double quantity, value;

	std::cout << line << std::endl;
	if (line.length() < 14)
		throw (LineTooShortException());
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw (LineSyntaxException());
	treatDate(line);
	quantity = treatValue(line);
	line.resize(10);
	std::map<std::string, float>::iterator it = _historicValues.lower_bound(line);
	--it;
	value = it->second;
	std::cout << line << " => " << quantity * value << std::endl;
}

float ft_stof(std::string value)
{
	float 				res;
	std::istringstream 	is(value);

	is >> res;
	return (res);
}