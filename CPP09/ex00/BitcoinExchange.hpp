#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <exception>
#include <algorithm>
#include <iterator>
#include <limits>

class BitcoinExchange
{
private:
	std::map<std::string, float> 	_historicValues;

public:

	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& parent);
	BitcoinExchange& operator=(const BitcoinExchange& parent);
	~BitcoinExchange(void);

	void	doAnalyse(char const *input);

	void	fillHistoricValues(void);
	void 	doInputValues(const char *filename);
	void	getAnalyseLine(std::string line);

	void 	treatDate(std::string date);
	float 	treatValue(std::string value);

	class FileErrorException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("An error occured with the input file !");}
	};

	class FileEmptyException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("The file is empty or do not contain any value !");}
	};

	class LineTooShortException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("Line is too short !");}
	};

	class InvalidCharacterException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("Invalid character found !");}
	};

	class LineSyntaxException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("Invalid line syntax ! (year-mm-dd | value)");}
	};

	class EarlyDateException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("Date can't be inferior of the bitcoin creation ! (2009-01-02)");}
	};

	class InvalidCalendarException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("Oups I think you missed something because there is only 12 months, and maximum 31 days in a month !");}
	};

	class InvalidNumberException : public std::exception
	{
	public:
		virtual const char * what() const throw () { return ("The value might be a positive float or int, between 0 and 1000 !");}
	};
};

float	ft_stof(std::string value);