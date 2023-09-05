#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <iterator>

class BitcoinExchange
{
private:
	std::map<std::string, std::string> 	_historicValues;
	std::map<std::string, std::string> 	_inputValues;


public:

	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& parent);
	BitcoinExchange& operator=(const BitcoinExchange& parent);
	~BitcoinExchange(void);

	void	doAnalyse(char const *input);

	void	fillHistoricValues(void);
	void 	fillInputValues(const char *filename);
	class FileErrorException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("An error occured with the input file !");}
	};
};
