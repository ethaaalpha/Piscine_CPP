#pragma once

class BitcoinExchange
{
private:
	/* data */
	BitcoinExchange(void);
public:
	BitcoinExchange(const BitcoinExchange& parent);
	BitcoinExchange& operator=(const BitcoinExchange& parent);
	~BitcoinExchange(void);
};

