#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& parent) { *this = parent;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& parent)
{
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}
